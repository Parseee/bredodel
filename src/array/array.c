#include "array.h"

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>

error_state Array_create(Array* array, size_t size)
{
    lassert(array, "");
    if (array->data) {
        report_error(LOGIC_ERROR, "already created");
    }

    array->data = calloc(size, sizeof(array->data));
    lassert(array->data, "");
    return OK;
}

error_state Array_insert(Array* array, int value)
{
    lassert(array, "");

    if (!(array->data = realloc(array->data, array->size + 1))) {
        free(array->data);
        array->size = 0;
        report_error(ALLOC_ERROR, "");
    }

    array->size += 1;
    array->data[array->size - 1] = value;

    return OK;
}

error_state Array_init(Array* array, size_t init_size, error_state (*input_handle)(int*, FILE*, size_t))
{
    lassert(array, "");

    for (size_t i = 0; i < init_size; ++i) {
        int val;
        input_handle(&val, stdin, 8); // how to handle error here???
        Array_insert(array, val);
        
    }

    return OK;
}

error_state Array_remove(Array* array, size_t index)
{
    lassert(array, "");

    if (0 > index || index >= array->size) {
        report_error(LOGIC_ERROR, "index out of range");
    }

    for (int i = index; i < array->size - 1; ++i) {
        array->data[i] = array->data[i + 1];
    }

    if (!(array->data = realloc(array->data, array->size - 1))) {
        free(array->data);
        array->size = 0;
        report_error(ALLOC_ERROR, "");
    }

    return OK;
}

error_state Array_kill(Array *array) {
    lassert(array, "");
    if (!array->data) {
        report_error(LOGIC_ERROR, "not created");
    }

    free(array->data);
    array->size = 0;

    return (!array->data) ? OK : ALLOC_ERROR;
}

error_state Array_print(Array *array) {
    lassert(array, "");

    if (!array->data) {
        report_error(LOGIC_ERROR, "not created");
    }

    for (size_t i = 0; i < array->size; ++i) {
        printf("%d ", array->data[i]);
    }
    printf("\n");

    return OK;
}

error_state Array_func(Array *array) {
    return OK;
}