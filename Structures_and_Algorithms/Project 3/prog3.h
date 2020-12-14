#ifndef prog3_H
#define prog3_H

//Macros
#define NO_ITEMS 16
#define ITEM_W 4

//#includes
#include <iostream>
#include <set>
#include <iomanip>

//Namespace
using namespace std;

//Declarations
void sieve(set < int >& s, int n);
void print_primes(const set < int >& s);

#endif // !prog3_H
