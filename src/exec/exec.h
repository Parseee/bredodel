#pragma once

#include <stddef.h>
#ifndef EXEC_H
#define EXEC_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../array/array.h"
#include "../logger/logger.h"

typedef enum { OK, INPUT_ERROR, LOGIC_ERROR } exec_state;

exec_state exec(Array* array);

#endif /* EXEC_H */