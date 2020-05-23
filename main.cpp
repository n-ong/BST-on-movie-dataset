#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include "movies.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file
  MovieBST movies;
  vector<string> movieNames;
  // Read each file and store the name and rating
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    movies.insert(movieName, movieRating);
    movieNames.push_back(movieName);//vector of movie names that will be used for timing the search function
  }
  movieFile.close();

  //program start
  if (strcmp(argv[1], "true") == 0)
    {
      cout<<endl;
      movies.printPreOrder();
      cout<<endl;
      movies.highestRating(argv[3]);
    }
  else
    {
      clock_t t;
      int w = strtol(argv[3], NULL, 10); //converts argv[3] to an int
      
      for (int i = 0; i < w; i++) 
	{
	  t = clock();
	  for (string item : movieNames)
	    {
	      movies.search(item);
	    }
	  t = clock() - t;
	  cout<<fixed<<showpoint;
	  cout<<setprecision(2);
	  cout<<"Time: "<< (double)t*1000000/CLOCKS_PER_SEC<<" micros"<<endl; 
	}
    }
      return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

