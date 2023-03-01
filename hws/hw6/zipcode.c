/** Program demonstrating parsing and linked lists. This program 
 * supports zip code lookup for any town in Massachusetts
 *
 * @author Blake Nelson, Cristobal Rincon Rogers
 *
 */

// #include "zipfilter.h"  no idea what this is for yet
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <forward_list>
#include "zipfed.hpp"

/** program to find the zip code for any town in Massachusetts
 *
 * @param argc is the number of field on command line - should be 2
 * @param argv is array of strings entered on command line - prog name
 * @return 0 for success
 */

#define SZ_FILENAME 129

ssize_t readln_cs2303 (char **lineptr, size_t *n, FILE *stream) {
  ssize_t bytes_read = -1;  // -1 will signify error reading line
  const int delim = '\n';   // each line terminated with \n

  // Verify the file is open
  if (stream == NULL) {
    return (ssize_t) -1;
  }

  // Each line of the FED ZIP CSV file is terminated by \n, so we
  // read up to and including the \r for the entire line
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

  std::forward_list<Zipfed *> linkedList;  // singly linked list of pointers to strings

  strncpy(infile, argv[1], SZ_FILENAME - 1);

  /**
   * Open input files - return  error on faulure
   * 
   */

  fdIn = fopen(infile, "r");
  if (fdIn == NULL) {
    fprintf(stderr, "cannot open %s for input - exiting\n", infile);
    return -2;
  }

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

    // // parse the zipcodes into string
    // const char *delim = ","; // comma is the delimeter
    // char *token;            // This will be the token we read using strtok
    // int recnum = 0;         // Each record in CSV is sequentially numbered

    // // first column is the 5-digit zip code as string
    // token = strtok(inbuf, delim);

    // printf("%s\n", token);
    linkedList.push_front(pZipfed);
  }

// TODO: IMPLEMENT BUBBLE SORTING ALGORITHM FOR THIS. THEN PRINT THEM.
   for(std::forward_list<Zipfed *>::iterator it = linkedList.begin(); it != linkedList.end(); it++) {
    Zipfed * pTmpZipfed = *it;
    // pTmpZipfed->print_filtered();
  }

  return 0;
}
