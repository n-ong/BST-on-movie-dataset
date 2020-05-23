//Nick Ong
//MovieBST definitions
#include "movies.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

MovieBST::MovieBST() : root(0) {}

MovieBST::~MovieBST()
{
  clear(root);
}

void MovieBST::clear(Movie* movie) //recursively deletes nodes
{
  if (movie)
    {
      clear(movie->left);
      clear(movie->right);
      delete movie;
    }
}

void MovieBST::insert(const string movieTitle, const double movieRating)
{
  //int count = 0;
  //creating the root of the BST
  if (!root)
    {
      root = new Movie(movieTitle, movieRating, 0);
      //cout<< count<<endl;
      return;
    }
  
  //adding other Movie nodes
  Movie* iter = root;
  while (iter)
    {
      //count++;
      //checks if the title comes before iter's title
      if (movieTitle < iter->title)
	{
	  //checks if iter has a left child or not; if not then create the node
	  if (!(iter->left))
	    {
	      Movie* newMovie = new Movie(movieTitle, movieRating, iter->depth + 1);
	      newMovie->parent = iter;
	      iter->left = newMovie;
	      break;
	    }
	  //otherwise keep iterating
	  iter = iter->left;
	}
      //checks if the title comes after iter's title
      else if (movieTitle > iter->title)
	{
	  //checks if iter has a right child or not; if not then create the node
	  if (!(iter->right))
	    {
	      Movie* newMovie = new Movie(movieTitle, movieRating, iter->depth + 1);
	      newMovie->parent = iter;
	      iter->right = newMovie;
	      break;
	    }
	  //other keep iterating
	  iter = iter->right;
	}
    }
  //cout<< count<< endl;
}

void MovieBST::printPreOrder() const
{
  printPreOrderHelper(root);
}

void MovieBST::printPreOrderHelper(Movie* n) const
{
  if (n)
    {
      cout<<n->title<<", "<<n->rating<<", "<<n->depth<<endl;
      printPreOrderHelper(n->left);
      printPreOrderHelper(n->right);
    }
}

//public search function
bool MovieBST::search(string title) const
{
  return searchHelper(title);
}
//private search function
MovieBST::Movie* MovieBST::searchHelper(string title) const
{
  Movie* iter = root;
  while (iter)
    {
      string movieTitle = (iter->title).substr(0,title.length());
      if (title == movieTitle) //substring used for prefixes/title
	{
	  return iter;
	}
      else if (title < movieTitle)
	{
	  iter = iter->left;
	}
      else if (title > movieTitle)
	{
	  iter = iter->right;
	}
    }
  return 0;
}
//public search prefix function
void MovieBST::searchPrefix(string prefix) const
{
  vector<MovieBST::Movie*>* movieList = searchPrefixHelper(prefix);
  for (auto item : *movieList)
    {
      cout<<item->title<<endl;
    }
}
//private search prefix function
vector<MovieBST::Movie*>* MovieBST::searchPrefixHelper(string prefix) const
{
  vector<Movie*>* list = new vector<Movie*>();
  Movie* iter = searchHelper(prefix);//the first occurance of the prefix

  //iterative preorder traversal (I had to look this up online but I changed stuff around so my code would work)
  if (!iter)
    {
      return 0;
    }
  Movie *pre;
  while(iter != NULL)
    {
      if (iter->left == NULL)
	{
	  if ((iter->title).substr(0,prefix.length()) == prefix)
	    {
	      list->push_back(iter);
	    }
	  iter = iter->right;
	}
      else
	{
	  pre = iter->left;
	  while(pre->right!= NULL && pre->right != iter)
	    {
	      pre = pre->right;
	    }
	  if (pre->right == NULL)
	    {
	      pre->right = iter;
	      iter = iter->left;
	    }
	  else
	    {
	      pre->right = NULL;
	      if ((iter->title).substr(0,prefix.length()) == prefix)
		{
		  list->push_back(iter);
		}
	      iter = iter->right;
	    }
	}
    }
  return list;
}
//public highest rating function
void MovieBST::highestRating(string prefix) const
{
  vector<MovieBST::Movie*>* movieList = searchPrefixHelper(prefix);
  Movie* highestRatedMovie = (*movieList)[0];
  for (int i = 1; i < movieList->size(); i++)
    {
      if ((*movieList)[i]->rating > highestRatedMovie->rating)
	{
	  highestRatedMovie = (*movieList)[i];
	}
    }

  cout<<"Best movie is " << highestRatedMovie->title<<" with rating "<< highestRatedMovie->rating<< endl;
  delete movieList;
}
