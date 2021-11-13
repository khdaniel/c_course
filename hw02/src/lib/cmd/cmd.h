#ifndef CMD_H
#define CMD_H

typedef enum {WRONG_ENCODING=-100, CP1251=0, KOI8, ISO8859} encoding;

typedef struct {
    char *inputFilePath;
    char *outputFilePath;
    encoding sourceEncoding;
} cmdArgs;

void showCmdArgsUsageMessageAndFail();

cmdArgs* parseCmd(int, char**);

char* processArgumentValue(char*);

encoding processProvidedEncoding(char*);

#endif
