/** Program demonstrating parsing and linked lists. This program 
 * supports zip code lookup for any town in Massachusetts
 *
 * @author Blake Nelson, Cristobal Rincon Rogers
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <forward_list>
#include "zipfed.hpp"
#include "mystring.h"
#include <ctype.h>

/** program to find the zip code for any town in Massachusetts
 *
 * @param argc is the number of field on command line - should be 2
 * @param argv is array of strings entered on command line - prog name
 * @return 0 for success
 */

#define SZ_FILENAME 129
std::forward_list<Zipfed *> linkedList;  // singly linked list of pointers to strings

/**
 * @brief Comparator function used for sorting function to order strings lexicographically.
 * 
 * @param pZip1 pointer to a Zipfed struct
 * @param pZip2 pointer to a Zipfed struct
 * @return true pZip1 is less than pZip2
 * @return false pZip1 is greater than or equal to pZip2
 */
  bool comparator_function(Zipfed* pZip1, Zipfed* pZip2) {
    return (pZip2->getCity().compare(pZip1->getCity()) > 0);
  }

/**
 * @brief reads the next line in a csv file
 * 
 * @param lineptr pointer to line in csv.
 * @param n size of lineptr buffer. default input 0, to allocate memory.
 * @param stream file that we are reading from
 * @return ssize_t number of characters read from the lineptr. 
 */
ssize_t readln_cs2303 (char **lineptr, size_t *n, FILE *stream) {
  ssize_t bytes_read = -1;  // -1 will signify error reading line
  const int delim = '\n';   // each line terminated with \n

  // Verify the file is open
  if (stream == NULL) {
    return (ssize_t) -1;
  }

  // Each line of the FED ZIP CSV file is terminated by \n
  bytes_read = getdelim (lineptr, n, delim, stream);

  // Remove the \n at the end of the line by replacing with NULL terminator
  // Expect length of at least 2 for the \n at end of a line
  for (int i = bytes_read - 1; i >= 0; i--) {
    if (((*lineptr)[i] == '\n')) {
      (*lineptr)[i] = '\0';
    }
  }
    
  return bytes_read;
}

/**
 * @brief extracts the zipcodes of the desired city in Massachussets.
 * 
 * @param city City name in Massachussets
 */
void filter(const char* city) {
  // print filtered list
  int len = mystrlennewline(city);
  char *upperCaseCity = (char *)calloc(len+1, sizeof(char *));

  // EXTRA CREDIT:: sets any input to capital letters, so all input is valid.
  for (int i = 0; i < len; i++) {
    *(upperCaseCity + i) = toupper(city[i]); // places each character of the previous
  }

  upperCaseCity[len + 1] = '\n'; // add newline character to end of character

  for (std::forward_list<Zipfed *>::iterator it = linkedList.begin(); it != linkedList.end(); it++)
  {
    Zipfed *pTmpZipfed = *it;
    const char *curr_str = pTmpZipfed->getCity().c_str();
    if ((strcmp(curr_str, upperCaseCity)) == 0)
    {
      pTmpZipfed->print_zipcode();
    }
    }
}



int main (int argc, char *argv[]) {
  
  if (argc < 2) {
      fprintf(stderr, "Not enough input arguments"); // throw error when not enough parameters
      return -1;
  }

  char infile[SZ_FILENAME]; // Path/name of input file
  FILE *fdIn;

  ssize_t chars_read;       // number of chars read for line of input
  char *inbuf = NULL;       // input file has 1 record per line to buffer
  size_t sz_inbuf = 0;      // // current size of the input record

  

  strncpy(infile, argv[1], SZ_FILENAME - 1);

  // Open input files - return  error on faulure

  fdIn = fopen(infile, "r");
  if (fdIn == NULL) {
    fprintf(stderr, "cannot open %s for input - exiting\n", infile);
    return -2;
  }
 
  char *buffer = NULL;
  size_t sz_buffer = 0;
  int numChars = 0;

  
    char prompt[] = "Type a City to search or <Ctrl-d> to end: ";
        fprintf(stdout, "%s", prompt);
        fflush(stdout);

  while((numChars = getline(&buffer, 
       &sz_buffer, stdin)) != EOF) { 

    while((chars_read = readln_cs2303 (&inbuf, &sz_inbuf, fdIn)) != EOF) {
      if(chars_read == 0) {
        continue;
      }
      

    Zipfed *pZipfed = new Zipfed();
    if(pZipfed->parse_zip_cs2303(inbuf) != 0) {
      fprintf (stderr, "failed to process input record - exiting\n");
      fclose (fdIn);
      return -4;
    }

          linkedList.push_front(pZipfed);
        }

      
        linkedList.sort(comparator_function);
        filter(buffer);

        free(buffer);
        buffer = NULL;
        sz_buffer = 0;

        fprintf(stdout, "%s", prompt);
        fflush(stdout);
      }

       return 0;
  }


  

 


