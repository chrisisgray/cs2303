/**
 * @file generate.h
 * @author Cristobal Rincon Rogers
 * @brief generate.h contains defined constants and function prototypes for generate.c
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef GENERATE_H
#define GENERATE_H


char generateChar();
char* generateStr(int length);
int generateYear();

#define MAX_CHAR_RANGE 'z'

#define LOWER_NUMERIC_RANGE '0'
#define UPPER_NUMERIC_RANGE '9'

#define LOWER_UPPERCASE_RANGE 'A'
#define UPPER_UPPERCASE_RANGE 'Z'

#define LOWER_LOWERCASE_RANGE 'a'
#define UPPER_LOWERCASE_RANGE 'z'

#endif