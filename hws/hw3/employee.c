#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"
#include "employee.h"
#include "generate.h"

/**
 * @author Cristobal Rincon Rogers
 * @brief Allocates a struct of type Employee and fills it with data passed as parameters
 * 
 * @param name a character array containing the name of the employee. Max name is 20 characters.
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

    newEmployee->name = name; //copies the name into the struct
    newEmployee->birth_year = birth_year;  //assigns the birth_year to the struct pointer
    newEmployee->start_year = start_year;   //assigns the start year to the struct pointer

    return newEmployee;
}

void printEmployee(Employee *employee) {
    printf("Employee name: %s\n", employee->name);
    printf("Employee birth year: %d\n", employee->birth_year);
    printf("Employee start year: %d\n", employee->start_year);
}

unsigned char validate (char* name) {
    int length = mystrlen(name);

    return ((length < MAX_EMPLOYEE_NAME_LENGTH) && name[length + 1] == '\0');
}

Employee* generateEmployee(int nameLength) {

  Employee *emp;
  emp = make_employee(generateStr(nameLength), generateYear(), generateYear());

  return emp;
}

Employee **generateWorkforce(int size) {
  Employee **work = (Employee**) malloc((sizeof(Employee *) * size)); // array of pointers

  for (int i = 0; i < size; i++) {
        work[i] = generateEmployee(7);
  }

  return work;
}

void printWorkforce(Employee **work, int size) {
  for (int i = 0; i < size; i++) {
    printEmployee(work[i]);
  }
}

Employee **copyWorkforce(Employee **work, int size) {

  Employee **newWorkforce = (Employee **)malloc(sizeof(Employee *) * size);

  for (int i = 0; i < size; i++) {
    newWorkforce[i] = work[i];
  }
  return newWorkforce;
}

void freeTheEmployees(Employee **work, int size) {
  for (int i = 0; i < size; i++) {
    free(work[i]);
  }
}

Employee **deepCopyWorkforce(Employee **work, int size) {
    Employee **newWorkforce = (Employee **)malloc(sizeof(Employee *) * size);

  for (int i = 0; i < size; i++) {
    Employee *emp = work[i];
    newWorkforce[i] = make_employee(emp->name, emp->birth_year, emp->start_year);
  }
  return newWorkforce;
}
