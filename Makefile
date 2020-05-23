movies.o: movies.cpp movies.h
	g++ -std=c++11 movies.cpp -c

main.o: main.cpp movies.h
	g++ -std=c++11 main.cpp -c

runMovies: movies.o main.o
	g++ movies.o main.o -o runMovies
