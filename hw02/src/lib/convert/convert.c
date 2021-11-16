#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include <stdbool.h>

#define BUFFER_SIZE 1024

letter *convertLetterEncoding(const long map[256], uchar source) {               
    long c = map[(uchar)source];
    char *lvl;
    letter *result = (letter*) malloc(sizeof(letter));
	if (c < 0x80) {
        lvl = (char*) malloc(1);
		lvl[0] = c;          
        result->lsz = 1;
        result->lvl = lvl;      
	}
	if (c >= 0x80 && c < 0x800) {
        lvl = (char*) malloc(2);
        lvl[0] = (c >> 6) | 0xc0;
        lvl[1] = (c & 0x3f) | 0x80;         
        result->lsz = 2;
        result->lvl = lvl;               
	}        
    return result;
}

void letterCleanup(letter *val) {
    free(val->lvl);
    free(val);
}

void convertBufferEncoding(const long map[256], uchar *sourceBuffer, size_t bufferSize, FILE* outputFile) {    
    for (size_t i = 0; i < bufferSize; i++) {        
        letter *lt = convertLetterEncoding(map, sourceBuffer[i]);  
        fwrite(lt->lvl, lt->lsz, 1, outputFile);
        letterCleanup(lt);
    }        
}

void convertFileEncoding(const long map[256], char *sourceFilePath, char *destFilePath) {
    uchar *sourceBuffer;    
    FILE *sourceFile = fopen(sourceFilePath, "r");
    FILE *destFile = fopen(destFilePath, "w");
    uchar bomMarker[] = {0xEF, 0xBB, 0xBF};
    fwrite(bomMarker, 3, sizeof(uchar), destFile); 
    
    while(true) {        
        sourceBuffer = (uchar*) malloc(BUFFER_SIZE+1);
        size_t bufferLength = fread(sourceBuffer, sizeof(uchar), BUFFER_SIZE, sourceFile);                                 
        convertBufferEncoding(map, sourceBuffer, bufferLength, destFile);                                    
        free(sourceBuffer);
        if ((bufferLength < BUFFER_SIZE) | feof(sourceFile)) {            
            break; 
        }                        
    }         

    fclose(sourceFile);
    fflush(destFile);
    fclose(destFile);
}
