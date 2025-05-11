//
// Created by lukas on 17.04.2025.
//

#include "generate-array.h"

#include <stdlib.h>

int* generateArray(int start, int end) {
    int* numbers = malloc(sizeof(int) * (end - start + 1));

    for (int i = 0; start <= end; i++) {
        numbers[i] = start++;
    }

    return numbers;
}
