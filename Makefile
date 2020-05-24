all: runMovies tests

movies.o: movies.cpp movies.h
	g++ movies.cpp -c

main.o: main.cpp movies.h
	g++ main.cpp -c

runMovies: movies.o main.o
	g++ movies.o main.o -o runMovies

tests.o: tests.cpp tests.h 
	g++ tests.cpp -c

tests: tests.o movies.o
	g++ tests.o movies.o -o tests
	./tests

clean:
	rm tests runMovies
