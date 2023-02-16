all:  sorttest sorttest2

sorttest2: sorttest2.o sort.o timesort.o generate.o
	gcc -g sorttest2.o sort.o timesort.o generate.o -o sorttest2

sorttest2.o: sorttest2.c sort.h generate.c generate.h
	gcc -g -c --std=gnu89 sorttest2.c

sorttest: sorttest.o sort.o timesort.o
	gcc -g sorttest.o sort.o timesort.o -o sorttest

sorttest.o: sorttest.c sort.h
	gcc -g -c --std=gnu89 sorttest.c

sort.o: sort.c sort.h
	gcc -g -c --std=gnu89 sort.c

generate.o: generate.c generate.h
	gcc -c generate.c

timesort.o: timesort.c sort.h
	gcc -g -c --std=gnu89 timesort.c

clean:
	rm -f  *.o sorttest sorttest2

docs:
	doxygen
	cp -rp html/* ~/public_html/hw4
