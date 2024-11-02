#include "exec.h"

#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../array/array.h"

static exec_state input_handle(int* res, char* input_string, FILE* file, size_t lengh)
{
    if (fgets(input_string, lengh, file)) {
        report_error(INPUT_ERROR);
    }
    char* end_ptr = NULL;
    *res = strtoll(input_string, &end_ptr, 10);
    if ((*res == INT_MAX || *res == INT_MIN) && errno != ERANGE) {
        report_error(INPUT_ERROR);
    }
    return OK;
}

exec_state exec(Array* array)
{
    lassert(array, "");

    fprintf(stdout, "Enter command: ");

    char input_string[8];

    int mode = 0;
    input_handle(&mode, input_string, stdin, 1);
    int val = 0;
    switch (mode) {
    case (1):
        Array_create(array);
        break;
    case (2):
        input_handle(&val, input_string, stdin, 1);
        Array_add(array, val);
        break;
    case (3):
        input_handle(&val, input_string, stdin,1);
        Array_remove(array, val);
        break;
    case (4):
        Array_func(array);
        break;
    default:
        report_error(LOGIC_ERROR);
    }

    return OK;
}