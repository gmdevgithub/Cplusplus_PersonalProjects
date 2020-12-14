/*
Giovanni J Moscato
Section: 003
Instructors: John Winans, Venkata Surya Vamsi Maddukuri
Date:10/20/2019
Assignment: Project 5

The problem is known as the Josephus problem and postulates a group of people of size
N >= 1 are standing in a circle waiting to be eliminated.
*/

#include "prog5.h"

/**
* It reads the input values N, M and K
*
* It reads the input values N, M and K
* of the struct args in when the program prompts for them and prints out
* those values on stdout.You can find the definition of the struct args in the
* header file prog5.h, which is defined as struct args { unsigned N, M, K; }; The
* routine prints out those values on stdout, and fills the names of people in
* the list L.
*
* @param names is a list object.
* @param in is argument object.
*
*
* @return is void
*
* @note will call print primes when finished, passing the complete set
*
* @warning
* For insert: If a single element is to be inserted, there are no changes in the container in case of exception (strong guarantee).
* Otherwise, the container is guaranteed to end in a valid state (basic guarantee).
* If allocator_traits::construct is not supported with the appropriate arguments for the element constructions,
* or if an invalid position is specified, it causes undefined behavior.
* For erase: Unless the container's comparison object throws, this function never throws exceptions (no-throw guarantee).
* Otherwise, if a single element is to be removed, there are no changes in the container in case of exception (strong guarantee).
* Otherwise, the container is guaranteed to end in a valid state (basic guarantee).
* If an invalid position or range is specified, it causes undefined behavior.
*
* @bug If a user enters a negative number no output is shown
*****************************************************************************/
void init_vals(list < string >& names, args& values)
{
	cout << "Number of people ? " << values.N;
	cout << "Index for elimination ? " << values.M;
	cout << "Index for printing ? " << values.K;

}


/**
* This routine can be used to print the elements in the integer set s
*
* This routine can be used to print the elements in the integer set s (NO_ITEMS = 16 primes per line and ITEM_W = 4
* spaces allocated for each prime).
*
* @param s complete set that was passed by reference
*
* @return is void
*
* @note uses an iterator as required by most STL containers to iterate through
*
* @warning
*
*
* @bug If a user enters a negative number no output is shown
*****************************************************************************/
//void print_list(const list < string >& L, const unsigned& cnt) : It prints out the
//contents of the list L at the beginning and after removing K names(each
//	time) from the list, until only one name remains in the list, where cnt has
//	an initial value 0 and it indicates the total number of removals so far.At
//	The Josephus Problem
//	2
//	the end, it also prints the name of the last remaining person.For printout,
//	print only up to 12 names in a single line, where the names are separated
//	by single spaces.

void print_list(const list < string >& names, const unsigned& cnt)
{



}


#if 1
int main()
{

	list <string> names;
	int cnt = 0;
	args values;

	init_vals(names, values);


	/*Name the people in the circle in the following sequence : A1, A2 … A9, B1, B2 … B9,
		C1, C2 …, and start counting from the person A1.Enter input values N, M and K
		when the program prompts for them and use a list <string> container to store the
		names of N people*/


		/*The main() routine first calls the routine int_vals() and initializes cnt to 0, and
			then calls the print_list() to print out the names of people in circle.After that it
			locates the M - th person in the list, and using the member function erase(), it
			removes that person from the list, and by calling the print_list() prints out the
			current contents of the list.This process continues(in a loop) until only one person
			remains in the list.Note: (a)If i(with initial value 0) indicates the position of a
			person in list L, then the statement : j = (i + M – 1) % L.size() returns the position
			of the M - th person from the position i. (b)Since the argument to the erase()
			function is an iterator, you can convert the index value j to an iterator by the
			advance(p, j) function, where p = L.begin().*/

			/*To store the names in an empty list, first change the size of the list to N, and then
				use the generate() function in the STL.The last argument to this function is the
				function object SEQ(N), which is defined in the header file prog5.h.To use the
				header file in your program, insert the following statement at the top of your source
				file : #include “ / home / cs340 / progs / 19f / p5 / prog5.h”.*/

	return 0;
}
#endif