#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef struct {
    char name[FILENAME_MAX];
    uint power;
    uint speed;
} ITEM;
