#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_EMPLOYEE_NAME_LENGTH 10 // employees can only have names of 20 characters long

typedef struct _employee {
    char* name;
    int birth_year;
    int start_year;
} Employee;

// function prototypes
Employee *make_employee(char *name, int birth_year, int start_year);
void printEmployee(Employee *employee);
unsigned char validate(char *name);
Employee *generateEmployee(int nameLength);
Employee **generateWorkforce(int size);
void printWorkforce(Employee **work, int size);
Employee **copyWorkforce(Employee **work, int size);
void freeTheEmployees(Employee **work, int size);
Employee **deepCopyWorkforce(Employee **work, int size);

#endif