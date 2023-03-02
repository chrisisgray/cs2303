/** mystring.h
 * @author Mike Ciaraldi, Blake Nelson, Cristobal Rincon Rogers
 * My own versions of some of the C-style string functions
*/
#ifndef MYSTRING_H		// Remember guard
#define MYSTRING_H

// Function prototype(s):
char* mystrdup(const char* src);
int mystrlen(const char *src);
char* mystrcpy(char* dest, const char* src);
char* mystrcat(char* des, const char* src);
char* mystrncat(char* des, const char* src, size_t n);
char* mystrncpy(char* des, const char* src, size_t n);
char* mystrndup(const char* src, size_t n);
char *mychardup(const char *src);
int mystrlennewline(const char* src);

#endif
