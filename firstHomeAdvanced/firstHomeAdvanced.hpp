#ifndef FIRSTHOMEADVANCED_HPP  //add include guard
#define FIRSTHOMEADVANCED_HPP

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <string>
#include <cmath>
#include <algorithm>
#include <iterator>     //to use std::merge 

int MAC (int x, int y, int & sum);
int Square(int x);

std::vector<int> combineVectors(const std::vector<int>::iterator firstVecBeg, const std::vector<int>::iterator firstVecEnd, const std::vector<int>::iterator secondVecBeg, const std::vector<int>::iterator secondVecEnd);
std::forward_list<int> reverseFrowardList(std::forward_list<int> & sourceForwardList);
void printList(std::list<std::string> const& list);
std::list<std::string> createNumber(int value, int powOfValue);

#endif
