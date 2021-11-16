#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "utils.h"

bool filePathExists(char *filePath) {
    struct stat buffer;
    return stat(filePath, &buffer) == 0;
}

void showMessageAndAbort(const char *message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}
