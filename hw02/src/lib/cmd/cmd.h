#ifndef CMD_H
#define CMD_H

#include "../convert/convert.h"

typedef struct {
    char *inputFilePath;
    char *outputFilePath;
    char *sourceEncodingStr;
    encoding sourceEncoding;
} cmdArgs;

void showCmdArgsUsageMessageAndFail();

cmdArgs* parseCmd(int, char**);

char* processArgumentValue(char*);

encoding processProvidedEncoding(char*);

void cmdArgsCleanup(cmdArgs*);

#endif
