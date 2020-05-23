//Nick Ong
//MovieBST declarations
#include <vector>
#include<iostream>
#include<string>

using namespace std;

class MovieBST{
 public:
  MovieBST();
  ~MovieBST();
  void insert(const string movieTitle, const double movieRating);
  void printPreOrder() const;
  bool search(string title) const;
  void searchPrefix(string prefix) const;
  void highestRating(string prefix) const;

 private:
  struct Movie
  {
    string title;
    double rating;
    int depth;
    Movie *parent, *left, *right;
    Movie(string movieTitle, double movieRating, int movieDepth) : title(movieTitle), rating(movieRating), depth(movieDepth), parent(0), left(0), right(0){}
  };
  Movie* searchHelper(string title) const;
  vector<Movie*>* searchPrefixHelper(string prefix) const;
  void printPreOrderHelper(Movie* n) const;
  void clear(Movie* movie);

  Movie* root;
};

