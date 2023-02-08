#include "calcGrades.h"

/** Program that calculates the average of an array
 *  by summing the elements and dividing by the length
 *  of the array
 *  
 *  Created by Cristobal Rincon
 */

int calcGrades(int length, int arr[]) {
  int total = 0;

   for(int i = 0; i <= length - 1; i++) {
	total += arr[i];
   }

   return total / length;

}
