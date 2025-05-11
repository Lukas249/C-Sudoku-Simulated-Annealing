//
// Created by lukas on 17.04.2025.
//

#include "get-random-number.h"
#include <stdlib.h>

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
