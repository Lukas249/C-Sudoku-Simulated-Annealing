//
// Created by lukas on 10.05.2025.
//

#include "fill-array.h"

void fillArray(bool *arr, int size, bool value) {
    for (int j = 0; j < size; j++) {
        arr[j] = value;
    }
}