#include <stdio.h>
#include <stdlib.h>
#include "lib/process_file.h"

processing parseCmdParams(int, char **);

int main(int argc, char **argv) {    

    if (argc < 2) {
        printf("Please provide the filepaths as the only cmd parameters...\n");
        exit(EXIT_FAILURE);
    }
   
    const int NUMBER_OF_FILES_TO_PROCESS = argc - 1;
    rawFile *rawFiles[NUMBER_OF_FILES_TO_PROCESS];
    
    for (int i = 0; i < NUMBER_OF_FILES_TO_PROCESS; i++) {
        rawFile *fileToProcess = malloc(sizeof(rawFile));
        fileToProcess->filePath = argv[i+1];        
        rawFiles[i] = fileToProcess;        
    }
    
    processing jobs = {rawFiles, NUMBER_OF_FILES_TO_PROCESS};    
    processFiles(&jobs);    

    // memory cleanup for "rawFile *fileToProcess = malloc(sizeof(rawFile));"       
    for (int i = 0; i < NUMBER_OF_FILES_TO_PROCESS; i++) {     
        free(rawFiles[i]);        
    }

    return EXIT_SUCCESS;
}
