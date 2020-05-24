movies.o: movies.cpp movies.h
	g++ -std=c++11 movies.cpp -c

main.o: main.cpp movies.h
	g++ -std=c++11 main.cpp -c

runMovies: movies.o main.o
	g++ movies.o main.o -o runMovies

tests.o: tests.cpp tests.h 
	g++ -std=c++11 tests.cpp -c

tests: tests.o movies.o
	g++ tests.o movies.o -o tests
	./tests
