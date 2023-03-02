
all: fed2cs2303 zipcode

fed2cs2303: fed2cs2303.o zipfed.o
	g++ -g fed2cs2303.o zipfed.o -o fed2cs2303

fed2cs2303.o: fed2cs2303.c zipfed.hpp
	g++ -g -c fed2cs2303.c

zipfed.o: zipfed.cpp zipfed.hpp
	g++ -g -c zipfed.cpp

zipfilter.o: zipfed.hpp
	g++ -g -c zipfilter.c

zipcode: zipcode.o zipfed.o mystring.o
	g++ -g zipcode.o zipfed.o mystring.o -o zipcode

zipcode.o: zipcode.c zipfed.hpp mystring.h mystring.c
	g++ -g -c zipcode.c

mystring.o: mystring.c mystring.h
	g++ -g -c mystring.c 

clean:
	rm *.o fed2cs2303 zipcode

docs:
	doxygen
	cp -rpT html/ ~/public_html/lab6
