
exe: vect2.o vec.o
	g++ vect2.o vec.o -o exe

vect2.o: vect2.cpp 
	g++ -c vect2.cpp

vec.o: vec.cpp vec.h
	g++ -c vec.cpp

clean:
	rm *.o exe
