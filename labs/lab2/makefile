all: at

at: at.o print_arrays.o
	gcc --std=c11 at.o print_arrays.o -o at

at.o: at.c print_arrays.h
	gcc --std=c11 -c at.c

print_arrays.o: print_arrays.c print_arrays.h
	gcc --std=c11 -c print_arrays.c

clean:
	rm -f *.o at

docs:
	doxygen
	cp -rpT html ~/public_html/lab_2
