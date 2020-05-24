#include <iostream>
#include "tests.h"
#include "movies.h"

using namespace std;

void runAll()
{
  test_constructor();
  test_insert();
  test_search();
  test_searchPrefix();
  test_highestRatedMovie();
}

void test_constructor()
{
  MovieBST newBST;
  if (!(newBST.getRoot()))
    {
      cout<<"PASSED CONSTRUCTOR TEST"<<endl;
    }
  else
    {
      cout<<"FAILED CONSTRUCTOR TEST"<<endl;
    }
}

void test_insert()
{
  insert_root();
  insert_other();
}

void test_search()
{
  search_exist();
  search_nonexist();
}

void test_searchPrefix()
{
  searchPrefix_exist();
  searchPrefix_nonexist();
}

void test_highestRatedMovie()
{
  highestRatedMovie_exist();
  highestRatedMovie_nonexist();
}

void insert_root()
{
  MovieBST newBST;
  newBST.insert("JOKER", 10);
  if (newBST.getRoot())
    {
      cout<<"PASSED INSERT ROOT TEST"<<endl;
    }
  else
    {
      cout<<"FAILED INSERT ROOT TEST"<<endl;
    }
}

void insert_other()
{
  MovieBST newBST;
  newBST.insert("JOKER", 10);
  newBST.insert("PARASITE", 10);
  newBST.insert("INCEPTION", 10);

  if (newBST.getRoot() && newBST.getLeft() && newBST.getRight())
    {
      cout<<"PASSED INSERT OTHER TEST"<<endl;
    }
  else
    {
      cout<<"FAILED INSERT ROOT TEST"<<endl;
    }
}

void search_exist()
{
  MovieBST newBST;
  newBST.insert("JOKER", 10);
  newBST.insert("PARASITE", 10);
  newBST.insert("INCEPTION", 10);

  if (newBST.search("INCEPTION"))
    {
      cout<<"PASSED SEARCH EXISTENCE TEST"<<endl;
    }
  else
    {
      cout<<"FAILED SEARCH EXISTENCE TEST"<<endl;
    }
}

void search_nonexist()
{
  MovieBST newBST;
  newBST.insert("JOKER", 10);
  newBST.insert("PARASITE", 10);
  newBST.insert("INCEPTION", 10);

  if (!(newBST.search("PULP FICTION")))
    {
      cout<<"PASSED SEARCH NONEXISTENCE TEST"<<endl;
    }
  else
    {
      cout<<"FAILED SEARCH NONEXISTENCE TEST"<<endl;
    }
}

void searchPrefix_exist()
{
  MovieBST newBST;
  newBST.insert("JOKER", 10);
  newBST.insert("PARASITE", 10);
  newBST.insert("INCEPTION", 10);

  if (newBST.search("P"))
    {
      cout<<"PASSED SEARCH PREFIX EXISTENCE TEST"<<endl;
    }
  else
    {
      cout<<"FAILED SEARCH PREFIX EXISTENCE TEST"<<endl;
    }
}

void searchPrefix_nonexist()
{
  MovieBST newBST;
  newBST.insert("JOKER", 10);
  newBST.insert("PARASITE", 10);
  newBST.insert("INCEPTION", 10);

  if (!(newBST.search("k")))
    {
      cout<<"PASSED SEARCH PREFIX NONEXISTENCE TEST"<<endl;
    }
  else
    {
      cout<<"FAILED SEARCH PREFIX NONEXISTENCE TEST"<<endl;
    }
}

void highestRatedMovie_exist()
{
  MovieBST newBST;
  newBST.insert("JOKER", 10);
  newBST.insert("PARASITE", 10);
  newBST.insert("INCEPTION", 10);

  if (newBST.search("P"))
    {
      cout<<"PASSED HIGHEST RATED MOVIE EXISTENCE TEST"<<endl;
    }
  else
    {
      cout<<"FAILED HIGHEST RATED MOVIE EXISTENCE  TEST"<<endl;
    }
}

void highestRatedMovie_nonexist()
{
  MovieBST newBST;
  newBST.insert("JOKER", 10);
  newBST.insert("PARASITE", 10);
  newBST.insert("INCEPTION", 10);

  if (!(newBST.search("K")))
    {
      cout<<"PASSED HIGHEST RATED MOVIE NONEXISTENCE TEST"<<endl;
    }
  else
    {
      cout<<"FAILED HIGHEST RATED MOVIE NONEXISTENCE  TEST"<<endl;
    }
}

int main()
{
  runAll();
  return 0;
}
