#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "logger/logger.h"
#include "array/array.h"
#include "exec/exec.h"



int main(void)
{
    log_create();

    Array array;

    bool quit = false;
    while (!quit) {
        if (exec(&array)) {
            //
        }
    }

    return EXIT_SUCCESS;
}