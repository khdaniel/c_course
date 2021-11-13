#include <stdio.h>
#include <stdlib.h>


void showMessageAndAbort(char *message) {
    printf("%s", message);
    exit(EXIT_FAILURE);
}
