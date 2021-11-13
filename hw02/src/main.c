#include <stdio.h>
#include <stdlib.h>
#include "lib/convert/convert.h"
#include "lib/cmd/cmd.h"

int main(int argc, char **argv) {    
    cmdArgs *args = parseCmd(argc, argv);       
    printf("InputFilePath: %s\nOutputFilePath: %s\nSourceEncoding: %d\n", args->inputFilePath, args->outputFilePath, args->sourceEncoding);
    free(args);
    args = NULL;
    return EXIT_SUCCESS;
}
