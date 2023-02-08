ctest: ctest.o mystring.o employee.o generate.o
	gcc ctest.o mystring.o employee.o generate.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

employee.o: employee.c employee.h
	gcc -c employee.c

generate.o: generate.c generate.h
	gcc -c generate.c

clean: 
	rm -f mystring.o ctest.o ctest employee.o generate.o

docs:
	doxygen
	cp -rpT html ~/public_html/hw3