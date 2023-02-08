#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

#define MAX_SIZE 20 // no maximum?

typedef struct _employee Employee {
    char name[MAX_SIZE];
    int birth_year;
    int start_year;
}

/**
 * @author Cristobal Rincon Rogers
 * @brief Allocates a struct of type Employee and fills it with data passed as parameters
 * 
 * @param name a character array containing the name of the employee
 * @param birth_year int describing the employee birth year
 * @param start_year int describing the year the employee began working at that company
 * @return Employee* pointer to Employee struct in heap
 */
Employee* make_employee(char* name, int birth_year, int start_year) {
    if(!validate(name)) {
        printf("Sorry. Name is invalid.\n");
        return (Employee *) 0; // returns null value
    }

    Employee *newEmployee = (Employee *)malloc(sizeof(Employee)); // allocates memory for a new struct

    newEmployee->name = mystrcpy(newEmployee->name, name); //copies the name into the struct
    newEmployee->birth_year = birth_year;  //assigns the birth_year to the struct pointer
    newEmployee->start_year = start_year;   //assigns the start year to the struct pointer

    return newEmployee;
}

unsigned char validate (char* name) {
    int length = mystrlen(name);

    return ((length < MAX_SIZE) && name[length + 1] == '\0');
}