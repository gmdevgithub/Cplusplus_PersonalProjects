#ifndef prog2_H
#define prog2_H

//Macros
#define ARR_SIZE 200
#define TEST_ARR_SIZE 100
#define SEED1 1
#define SEED2 3
#define LOW 1
#define HIGH 1000
#define ITEM_W 4
#define NO_ITEMS 16

//#includes
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

//Declarations
void Vectors(std::vector < int >& v1, std::vector < int >& v2, int s1, int s2);
void printVector(const std::vector < int > &v);
bool linearSearch(const std::vector < int > &v, int x);
bool binarySearch(const std::vector < int >& v, int x);
void sortVector(std::vector < int > &v);
int search(const std::vector < int >& v1, const std::vector < int >& v2, bool(*p) (const std::vector <int >&, int));
void printStat(int totalSucCnt, int vectorSz);

#endif // !prog2_H
