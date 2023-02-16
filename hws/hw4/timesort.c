#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sort.h"

/** Program which takes an array of integers, prints it,
 * sorts it, prints it again, and reports how long the sorting took.
 * @param a Array of integers.
 * @param count Number of integers in the array.
 * @param defaultFunc Boolean value dictating if array indexing or pointer operations are used for sorting
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

void timesort (int a[], int count, int defaultFunc) {

  struct timeval start_time; // time stamps for start and end of sorting
  struct timeval end_time;
  struct timeval sort_time; // Elapsed time while sorting

  printf("Unsorted array:\n");
  print_int_array(a, count);

  gettimeofday(&start_time, NULL); // Get timestamp

  if(defaultFunc) {
      sort_descending(a, count);
  } else {
      alt_sort_descending(a, count);
  }
  
  gettimeofday(&end_time, NULL); // Get timestamp

  printf("Sorted array (descending order):\n");
  print_int_array(a, count);

  printf("Timestamp before sorting: ");
  print_timeval(start_time); 
  printf("Timestamp after sorting: ");
  print_timeval(end_time);
  sort_time = timediff(start_time, end_time);
  printf("Time spent sorting: ");
  print_timeval(sort_time); 

// testing that timediff() now returns the correct value
  struct timeval time1 = {1003, 610};
  struct timeval time2 = {1005, 510};

  timediff(time1, time2);

  return; // nothing to return
}
