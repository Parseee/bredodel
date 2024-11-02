#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "../logger/logger.h"

#define DEBUG

typedef enum array_state { INPUT_OK, INPUT_FAILURE, READ_FAILURE } array_state;

typedef struct {
    int* data;
    size_t size;
} Array;

array_state Array_create(Array* array);
array_state Array_add(Array* array, int value);
array_state Array_remove(Array* array, int index);
array_state Array_func(Array* array);
array_state Array_print(Array* array);
array_state Array_kill(Array* array);

#endif /* ARRAY_H */