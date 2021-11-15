#include <stdio.h>
#include <stdlib.h>


void showMessageAndAbort(const char *message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}
