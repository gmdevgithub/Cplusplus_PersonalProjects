#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

#ifndef H_PROG8
#define H_PROG8

// data files
//Change these back to normal later*****************************************************************************************************************
#define D1 "/home/cs340/progs/19f/p8/prog8.d1"
#define D2 "/home/cs340/progs/19f/p8/prog8.d2"
#define D3 "/home/cs340/progs/19f/p8/prog8.d3"

#define INT_SZ 4    // width of integer
#define FLT_SZ 7    // width of floating-pt number
#define STR_SZ 12   // width of string

#define INT_LN 15   // no of integers in single line
#define FLT_LN 9    // no of floating-pt nums in single line
#define STR_LN 5    // no of strings in single line

// function and class prototypes

// stores items from input file into vector
template < typename T >
void get_list(vector < T >&, const char*);

// construct heap from items in vector
template < typename T, typename P >
void construct_heap(vector < T >&, P);

// class to print heap items

template < typename t >
class print_list 
{
	unsigned sz,  // heap size 
		wid, // min num of chars written in printout
		len, // max num of items printed in single line
		cnt; // counter for printout
public:
	print_list(const unsigned& = 1, const unsigned& = 1, const unsigned& = 1, const unsigned& = 0); // constructor
	void operator ( ) (const t&);
};

#endif

