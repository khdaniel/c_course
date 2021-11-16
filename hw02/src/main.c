#include <stdio.h>
#include <stdlib.h>
#include "lib/convert/convert.h"
#include "lib/cmd/cmd.h"


int main(int argc, char **argv) {     

    cmdArgs *args = parseCmd(argc, argv);      
    
    switch (args->sourceEncoding) {
        case CP1251:
            convertFileEncoding(CP1251ToUTF, args->inputFilePath, args->outputFilePath);
            break;
        case ISO8859:
            convertFileEncoding(ISO88595ToUTF, args->inputFilePath, args->outputFilePath);
            break;
        case KOI8:
            convertFileEncoding(KOI8ToUTF, args->inputFilePath, args->outputFilePath);
            break;
        default:
            break;
    }
    
    free(args->inputFilePath);
    free(args->outputFilePath);
    free(args->sourceEncoding);
    free(args);    

    return EXIT_SUCCESS;
}
