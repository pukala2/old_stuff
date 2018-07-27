
exe: main.o plan.o
	clang++ main.o planer.o -l sqlite3 -o exe

main.o: main.cpp
	clang++ -c main.cpp -l sqlite3

plan.o: planer.cpp planer.h
	clang++ -c planer.cpp -l sqlite3

clean:
	rm *.o exe *.db .db
