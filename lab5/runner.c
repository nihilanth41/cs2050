#include <stdio.h>
#include "function.h"

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        printf("Usage: <your name>\n");
        return 1;
    }

    displayMessage(argv[1]);
    
    return 0;
}
