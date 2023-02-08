#include <stdio.h>
#include <stdlib.h>
#include "generate.h"

char generateChar() {

    char randChar = rand() % MAX_CHAR_RANGE;

    if (randChar >= LOWER_NUMERIC_RANGE && randChar <= UPPER_NUMERIC_RANGE) {
        return randChar;
    } 
    else if (randChar >= LOWER_UPPERCASE_RANGE && randChar <= UPPER_UPPERCASE_RANGE) {
        return randChar;
    } 
    else if (randChar >= LOWER_LOWERCASE_RANGE && randChar <= UPPER_LOWERCASE_RANGE) {
        return randChar;
    } 
    else {
        generateChar();
    }
}

char* generateStr(int length) {
    int i;
    int lenWithTerm = length + 1;

    char *str = (char*) malloc(lenWithTerm);

    if(str == 0) {
        printf("No memory here folks\n");
    }

    for (i = 0; i < length; i++) {
        str[i] = generateChar();
    }
        
    return str;
}

int generateYear() {
    return rand() % 2023; 
}