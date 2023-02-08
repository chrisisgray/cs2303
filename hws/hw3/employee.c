/**
 * @file employee.c
 * @author Cristobal Rincon Rogers 
 * @brief employee.c allows for manipulation of employee structs. 
 * @version 0.1
 * @date 2023-02-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

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

/**
 * @brief the printEmployee() function prints the elements of the employee struc
 * 
 * @param employee pointer to employee struct
 */
void printEmployee(Employee *employee) {
    printf("Employee name: %s\n", employee->name);
    printf("Employee birth year: %d\n", employee->birth_year);
    printf("Employee start year: %d\n", employee->start_year);
}

/**
 * @brief the validate() function verifies that a name is within the max employee name and null terminates
 * 
 * @param name pointer to string
 * @return unsigned char returns boolean value. 1: name is valid. 0: name is invalid.
 */
unsigned char validate (char* name) {
    int length = mystrlen(name);

    return ((length < MAX_EMPLOYEE_NAME_LENGTH) && name[length + 1] == '\0');
}

/**
 * @brief the generateEmployee() function auto populates an Employee with random values
 * 
 * @param nameLength desired length of employee name
 * @return Employee* pointer to newly created employee
 */
Employee* generateEmployee(int nameLength) {

  Employee *emp;
  emp = make_employee(generateStr(nameLength), generateYear(), generateYear());

  return emp;
}

/**
 * @brief the generateWorkforce() function generates an array of pointers to Employees of a desired size
 * 
 * @param size length of array
 * @return Employee** array of Employee pointers
 */
Employee **generateWorkforce(int size) {
  Employee **work = (Employee**) malloc((sizeof(Employee *) * size)); // array of pointers

  for (int i = 0; i < size; i++) {
        work[i] = generateEmployee(7);
  }

  return work;
}

/**
 * @brief the printWorkforce() function prints an array of Employees
 * 
 * @param work array of Employee pointers
 * @param size number of elements in array of Employee pointers
 */
void printWorkforce(Employee **work, int size) {
  for (int i = 0; i < size; i++) {
    printEmployee(work[i]);
  }
}

/**
 * @brief the copyWorkforce() function shallow copies an existing array of Employee pointers
 * 
 * @param work array of Employee pointers
 * @param size number of elements in array of Employee pointers
 * @return Employee** array of shallow copied Employee pointers
 */
Employee **copyWorkforce(Employee **work, int size) {

  Employee **newWorkforce = (Employee **)malloc(sizeof(Employee *) * size);

  for (int i = 0; i < size; i++) {
    newWorkforce[i] = work[i];
  }
  return newWorkforce;
}

/**
 * @brief the freeTheEmployees() function frees allocated memory created with malloc()
 * 
 * @param work array of Employee pointers
 * @param size number of elements in array of Employee pointers
 */
void freeTheEmployees(Employee **work, int size) {
  for (int i = 0; i < size; i++) {
    free(work[i]);
  }
}

/**
 * @brief the deepCopyWorkforce() function deep copies an existing array of Employee. 
 * This function returns an array of new Employee pointers with the copied content inside the structs.
 * 
 * @param work array of employee pointers
 * @param size number of elements in Employee pointers
 * @return Employee** array of deep copied Employee pointers
 */
Employee **deepCopyWorkforce(Employee **work, int size) {
    Employee **newWorkforce = (Employee **)malloc(sizeof(Employee *) * size);

  for (int i = 0; i < size; i++) {
    Employee *emp = work[i];
    newWorkforce[i] = make_employee(emp->name, emp->birth_year, emp->start_year);
  }
  return newWorkforce;
}
