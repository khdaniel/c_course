#include <stdio.h>
#include <stdlib.h>
#include "process_file.h"
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>

bool fileExists(rawFile *f) {
    struct stat buffer;
    return stat(f->filePath, &buffer) == 0;
}

int processFiles(processing *app) {           
    printf("=================================================================\n");
    for (int i = 0; i < app->fileCount; i++) {
        rawFile* file = app->files[i];  
        if (fileExists(file)) {
            printf("Processing file: %20s", file->filePath);
            showDetails(file->filePath);   
        } else {
            printf("Processing file: %20s doesn't exist......skipped\n", file->filePath);
        }
        printf("=================================================================\n");                
    }
    return EXIT_SUCCESS;
}



EOCDData getEOCD(FILE *fp) {
    uint32_t eocd_address = 0; 
    // get file size 
    fseek(fp, 0, 2);
    long file_size = ftell(fp);
    
    // retrieve EOCD if exists
    uint32_t signatureBuffer = 0;        
    EOCD *eocd = (EOCD*) malloc(sizeof(EOCD));
    for (long i = file_size; i != 0; --i) {
        fseek(fp, i - sizeof(uint32_t) , 0);
        fread(&signatureBuffer, sizeof(signatureBuffer), 1, fp);
        if (signatureBuffer == 0x06054b50) {
            eocd_address = ftell(fp);            
            fseek(fp, -sizeof(uint32_t), 1);          
            fread(eocd, sizeof(EOCD), 1, fp);             
            break;          
        }          
    }

    EOCDData result = {.address = eocd_address, .centralDirectoryOffset = eocd->centralDirectoryOffset};
    free(eocd);
    eocd = NULL;
    return result;
}

void printFileNames(FILE *fp, EOCDData *eocd) { 
    uint32_t signatureBuffer = 0;
    CDFH *cdfh = (CDFH*) malloc(sizeof(CDFH));  
    uint32_t current_offset = eocd->centralDirectoryOffset;        
    while (current_offset < eocd->address-sizeof(CDFH)) {            
        fseek(fp, current_offset, 0);     
        fread(&signatureBuffer, sizeof(signatureBuffer), 1, fp);
        if (signatureBuffer == 0x02014b50) {                  
            fread(cdfh, sizeof(CDFH), 1, fp);             
            printFileName(cdfh, fp);         
            current_offset += (sizeof(CDFH) + (cdfh->filenameLength) + (cdfh->fileCommentLength) + (cdfh -> extraFieldLength));         
        } else {               
            current_offset += 1;
        }                      
    }    
    free(cdfh);
    cdfh = NULL;
}

void printFileName(CDFH *cdfh, FILE *fp) {
    uint8_t *filename = (uint8_t*) malloc(cdfh->filenameLength + 1);
    fread(filename, sizeof(uint8_t), cdfh->filenameLength, fp);            
    filename[cdfh->filenameLength] = '\0';
    printf("%s\n", filename);
    free(filename);     
    filename = NULL; 
}

void showDetails(char *zipFilePath) {    
    FILE *fp = fopen(zipFilePath, "rb");    
    if (fp == NULL) {
        printf(" UNABLE TO OPEN THE FILE\n");
        return;
    }
    
    EOCDData eocd = getEOCD(fp);

    if (eocd.address) {
        printf(" is zipped.........  files: \n");
        printFileNames(fp, &eocd);
    } else {
        printf(" is not zipped......skipped\n");
    }
                   
    fclose(fp);
}



