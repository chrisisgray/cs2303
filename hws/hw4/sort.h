#ifndef SORT_H
#define SORT_H

// max number of microseconds
#define MAX_USEC 1000000 // 1,000,000

// Function prototypes:
void timesort (int a[], int count, int defaultFunc);
void print_int_array(int nums[], int count);
void sort_descending(int nums[], int count);
void alt_sort_descending(int nums[], int count);
void print_timeval(struct timeval t);
struct timeval timediff(struct timeval time1, struct timeval time2);

#endif
