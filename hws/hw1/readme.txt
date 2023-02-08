Cristobal Rincon Rogers

Num: A program to demo reading a number from the command line.

Grades: Simple program to store grades and calculates average of grades passed in.

Leap: Determines if a year is a leap year.

Instructions to Compile:

1. run make to compile all three programs.

2. to run num, type ./num some_number. This will return a message saying what number you typed in. 
Ex. ./num 2303

3. to run grades, type ./grades [list of ints]. The maximum number of arguments grades can take in is currently set to 20 by a variable called MAX_GRADES. You can change this in the grades.c file. After changing this value, run make again to update the executible file and dependencies. 
Ex. ./grades 1 2 3 4 5  --> returns avg. of 3


4. to run leap, type ./leap some_year in your terminal. This will return a message indicating if the year you typed in is a leap year or not.  
Ex. ./leap 1900 --> returns that 1900 is not a leap year.

