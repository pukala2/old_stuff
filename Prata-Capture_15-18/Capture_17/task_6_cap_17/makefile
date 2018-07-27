
exe: main.o ab.o
	g++ main.o ab.o -o exe

main.o: main.cpp
	g++ -c main.cpp

abstr_emp.o: ab.cpp ab.h
	g++ -c ab.cpp

clean:
	rm *.o exe
