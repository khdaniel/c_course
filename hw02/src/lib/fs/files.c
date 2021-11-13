#include <stdlib.h>
#include <sys/stat.h>
#include "files.h"

bool filePathExists(char *filePath) {
    struct stat buffer;
    return stat(filePath, &buffer) == 0;
}


