
all: fed2cs2303

fed2cs2303: fed2cs2303.o zipfed.o
	g++ -g fed2cs2303.o zipfed.o -o fed2cs2303

fed2cs2303.o: fed2cs2303.c zipfed.hpp
	g++ -g -c fed2cs2303.c

zipfed.o: zipfed.cpp zipfed.hpp
	g++ -g -c zipfed.cpp

zipfilter.o: zipfed.hpp
	g++ -g -c zipfilter.c

clean:
	rm -r *.o fed2cs2303

docs:
	doxygen
	cp -rpT html/ ~/public_html/lab6
