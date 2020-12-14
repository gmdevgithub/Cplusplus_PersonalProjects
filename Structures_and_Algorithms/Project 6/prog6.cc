#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

#include "binTree.h"

#define SEED       1 // seed for RNGs

#define N1       100 // size of 1st vector container
#define LOW1    -999 // low val for rand integer
#define HIGH1    999 // high val for rand integer


#define N2        50 // size of 2nd vector container
#define LOW2  -99999 // low val for rand float
#define HIGH2  99999 // high val for rand float
#define PREC       2 // no of digits after dec pt

#define LSIZE     12 // no of vals printed on line
#define ITEM_W     7 // no of spaces for each item

// prints single val
template < class T > void print(const T&);

// prints data vals in tree
template < class T > void print_vals(binTree < T >&, const string&);

//The class RND1 can be
//used to generate random integers in the range
//[LOW1 = –999, HIGH1 = 999]

// class to generate rand ints
class RND1 
{
private:
	int low, high;
public:
	RND1(const int& l = 0, const int& h = 1) : low(l), high(h) { }
	int operator ( ) () const {
		return rand() % (high - low + 1) + low;
	}
};


//The class RND1 can be
//used to generate random integers in the range[LOW1 = –999, HIGH1 = 999] and the class RND2
//can be used to generate random floating - point numbers in the range[LOW2 = –999.99, HIGH2 =
//999.99].

// class to generate rand floats
class RND2 {
private:
	int low, high, prec;
public:
	RND2(const int& l = 0, const int& h = 1, const int& p = 0) :
		low(l), high(h), prec(p) { }
	float operator ( ) () const {
		return (static_cast <float>
			(rand() % (high - low + 1) + low)) / pow(10, prec);
	}
};

//The unary function print() can be used as an argument to the 
//member functions inorder() toprint the value of its argument x.

// prints out val passed as argument
template < class T >
void print(const T& x) 
{
	static unsigned cnt = 0;
	cout << setw(ITEM_W) << x << ' '; cnt++;
	if (cnt % LSIZE == 0) cout << endl;
}


//first, it prints
//name, which is the name of the tree, and it
//also prints the height of the tree.Then, it calls the
//member function inorder() 
//to print the data values in the tree in inorder.

// prints out height of bin tree and data val in each node in inorder
template < class T >
void print_vals(binTree < T >& tree, const string& name)
{
	cout << name << ": "; // print name of tree

	// print height of tree
	cout << "height of tree = " << tree.height() << endl << endl;//Height +1

	// print data values of tree in inorder
	cout << "Data values in '" << name << "' inorder:\n\n";
	tree.inorder(print); cout << endl;
}

// driver program: to test several member functions
// of bin tree class

int main()
{
	srand(SEED); // set seed for RNGs

	/*The function objects RND1() and RND2(), generated from these classes, are used to
	fill in the random values in vector containers vector < int > A(N1) and vector < float > B(N2) by
	using the generate() function in the STL, where N1 = 100 and N2 = 50 are the sizes of these two
	vectors.*/

	// create 1st vector and fill it with rand ints
	vector < int > A(N1); //{0,0,0,0................................}
	generate(A.begin(), A.end(), RND1(LOW1, HIGH1));//{4,23,152,32................................}

	// create bin tree with int vals in vector A,
	// and print all vals of tree

	binTree < int > first;
	for (unsigned i = 0; i < A.size(); i++)
		first.insert(A[i]);
	print_vals(first, "first"); cout << endl;

	// create 2nd vector and fill it with rand floats
	vector < float > B(N2);
	generate(B.begin(), B.end(), RND2(LOW2, HIGH2, PREC));//{1231.23, 245.45, 51.75................................}

	// create bin tree with float-pt vals in vector B,
	// and print all vals of tree

	binTree < float > second;
	for (unsigned i = 0; i < B.size(); i++)
		second.insert(B[i]);
	print_vals(second, "second"); cout << endl;

	

	return 0;
}
