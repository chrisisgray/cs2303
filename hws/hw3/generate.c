/**
 * @file generate.c
 * @author Cristobal Rincon Rogers
 * @brief generate.c creates characters, strings, and integers at random. 
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "generate.h"

/**
 * @brief the generateChar() function generates an alphanumeric character of value: 0-9, A-Z, a-z
 * 
 * @return char an alphanumeric character
 */
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

/**
 * @brief the generateStr() function generates random string of a specified length.
 * 
 * @param length desired length of string.
 * @return char* pointer to the string
 */
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

/**
 * @brief the generateYear() function returns a random year between 0 and 2023.
 *
 * @return int year between 0 and 2023.
 */
int generateYear() {
    return rand() % 2023; 
}