#include <stdlib.h>
#include <string.h>
#include "cmd.h"
#include "../fs/files.h"
#include "../utils/utils.h"

const char* MSG_APP_USAGE = "Please provide required parameters: " \
        "\n\t-f <path to the source file>" \
        "\n\t-o <path to the encoding conversion result file>" \
        "\n\t-e <source encoding cp1251|koi8|iso8859>\nAbort.\n";

const char* MSG_ENCODING_PARAM_USAGE = "The only possible values for the source encoding provided by -e key are:" \
        "\n\tcp1251" \
        "\n\tkoi8" \
        "\n\tiso8859\nAbort.\n";

const char* MSG_INPUT_FILE_DOESNT_EXIST = "The provided path for the input file doesn't exist.\nAbort.\n";

cmdArgs* parseCmd(int argc, char **argv) {   
    cmdArgs *result;
    char *inputFilePath = NULL;
    char *outputFilePath = NULL;
    char *sourceEncodingStr = NULL;
    encoding sourceEncoding = -1;
    
    // at least 7 arguments should be provided:
    // 0. programm
    // 1. -e key
    // 2. -e value
    // 3. -i key
    // 4. -i value
    // 5. -o key
    // 6. -o value
    // otherwise show app usage message and abort
    if (argc < 7) {
        showMessageAndAbort(MSG_APP_USAGE);
    }
    
    // process provided arguments with flags -i -o -e
    for (int i = 1; i < argc-1; i++) {
        char *flag = argv[i];
        char *flagValue = argv[i+1];      

        if (strcmp(flag, "-o") == 0) {
            outputFilePath = processArgumentValue(flagValue);  
            i++;          
        }             
        else if (strcmp(flag, "-f") == 0) {
            inputFilePath = processArgumentValue(flagValue);
            i++;
        }            
        else if (strcmp(flag, "-e") == 0) {
            sourceEncodingStr = processArgumentValue(flagValue);    
            i++;                          
        }                   
    }
    
    // check whether all required parameters were provided
    // otherwise show message and abort
    if (outputFilePath == NULL | inputFilePath == NULL | sourceEncodingStr == NULL) 
        showMessageAndAbort(MSG_APP_USAGE);
    
    // verify the provided encoding is in the list cp1251|koi8|iso8859
    // otherwise show message and abort    
    if ((sourceEncoding = processProvidedEncoding(sourceEncodingStr)) == WRONG_ENCODING) 
        showMessageAndAbort(MSG_ENCODING_PARAM_USAGE);
    
    // verify if the provided input file path exists
    // otherwise show message and abort
    if (!filePathExists(inputFilePath)) 
        showMessageAndAbort(MSG_INPUT_FILE_DOESNT_EXIST);

    // if all required parameters were provided 
    // and the provided source encoding seems correct value
    // and the provided input file exists
    // proceed 
    result = (cmdArgs*) malloc(sizeof(cmdArgs));    
    result->inputFilePath = inputFilePath;
    result->outputFilePath = outputFilePath;
    result->sourceEncodingStr = sourceEncodingStr;    
    result->sourceEncoding = sourceEncoding;

    return result; 
}

char* processArgumentValue(char* argument) {       
    size_t paramLen = strlen(argument);
    char *argumentValue = (char*) malloc(paramLen+1);
    strcpy(argumentValue, argument);
    argumentValue[paramLen] = '\0';    
    return argumentValue;
}

encoding processProvidedEncoding(char *encodingStr) {
    if (strcmp(encodingStr, "cp1251") == 0) return CP1251;
    else if (strcmp(encodingStr, "koi8") == 0) return KOI8;
    else if (strcmp(encodingStr, "iso8859") == 0) return ISO8859;
    else return WRONG_ENCODING;
}

void cmdArgsCleanup(cmdArgs *args) {
    free(args->inputFilePath);
    free(args->outputFilePath);
    free(args->sourceEncodingStr);
    free(args);
} 
