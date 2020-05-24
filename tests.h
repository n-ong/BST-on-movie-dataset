//Nick Ong
#ifndef TESTS_H
#define TESTS_H

#include <iostream>

using namespace std;

void runAll();
void test_constructor();
void test_insert();
void test_search();
void test_searchPrefix();
void test_highestRatedMovie();

//test cases
void insert_root();
void insert_other();

void search_exist();
void search_nonexist();

void searchPrefix_exist();
void searchPrefix_nonexist();

void highestRatedMovie_exist();
void highestRatedMovie_nonexist();
#endif
