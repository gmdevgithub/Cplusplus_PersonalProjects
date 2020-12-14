/*
Giovanni J Moscato
Section: 003
Instructors: John Winans, Venkata Surya Vamsi Maddukuri
Date:10/20/2019
Assignment: Project 5

The problem is known as the Josephus problem and postulates a group of people of size
N >= 1 are standing in a circle waiting to be eliminated.
*/

//#include "prog5.h" CUSTOM HEADER FOR VISUAL STUDIO
//******************* REMEMBER TO SWITCH TO TERMINAL USAGE BEFORE TURNING IN **********************************

//FOR TERMINAL USAGE:
#include " / home / cs340 / progs / 19f / p5 / prog5.h"


/*!Subroutines*/

/**
* This routine reads the input values N, M and K
*
* It reads the input values N, M and K
* of the struct args in when the program prompts for them and prints out
* those values on stdout.You can find the definition of the struct args in the
* header file prog5.h, which is defined as struct args { unsigned N, M, K; }; The
* routine prints out those values on stdout, and fills the names of people in
* the list L.
*
* @param names: is a list object.
*
* @param in: is argument object.
*
*
* @return is void
*
* @note changed N to values.N
*
* @warning Resize: If the operation decreases the size of the container, the function never throws exceptions (no-throw guarantee).
*					Otherwise, if an exception is thrown, the container is left with a valid state (basic guarantee):
*					Constructing elements or allocating storage may throw.
*
*		  Generate: Throws if any of gen, the element assignments or the operations on iterators throws.Note that invalid arguments
*					cause undefined behavior
*
* @bug could be an issue with resizing if the header file is changed & which would change the value of all M N K.
*****************************************************************************/
void init_vals(list < string >& names, args& values)
{
	cin >> values.N;/*!Program prompts for struct arg values*/
	cin >> values.M;
	cin >> values.K;

	cout << "Number of people ? " << values.N << endl;/*!Outputs the values of N M & K*/
	cout << "Index for elimination ? " << values.M << endl;
	cout << "Index for printing ? " << values.K << endl;
	cout << endl;

	names.resize(values.N);/*!Change size of the list to N*/

	generate(names.begin(), names.end(), SEQ(values.N));/*!Fill list with names of people using std::generate() function*/
														/*!Unary Predicate is SEQ which is defined in our header*/
}

/**
* This routine prints out the contents of the list L
*
* It prints out the contents of the list L at the beginning and after removing K names(each
* time) from the list, until only one name remains in the list, where cnt has an initial value 0
* and it indicates the total number of removals so far.
* At The Josephus Problem 2 the end, it also prints the name of the last remaining person.For printout,
* print only up to 12 names in a single line, where the names are separated by single spaces.
*
* @param names: is the filled list of names, filled by first subroutine
*
* @param cnt: count variable defined in main routine
*
* @return is void
*
* @note three levels of an if statment are included. The nested if statment first handles the case of cnt == 0, then all values in between,
* only to reach a cnt of 40 resulting in one final output before exiting.
*
* @warning changing NO_ITEMS defined in header file could produce unwanted results. Function parameters are constant and cannot be
* changed only accessed. Format follows given output and may not match exactly to data.
*
*
* @bug if cnt is not 0-40 there could be format issues. Did not check for string issues.
*****************************************************************************/
void print_list(const list < string >& names, const unsigned& cnt)/*!Constant so we dont corrupt the data of the list */
{
	if (cnt == 0)/*! Before making the first iteration */
	{
		int count = 0;

		cout << "Inital group of people" << endl;
		cout << "----------------------" << endl;

		for (auto it = names.begin(); it != names.end(); ++it)/*!Print out the initial list of names */
		{
			cout << *it << " ";
			count++;
			if (count == NO_ITEMS)
			{
				std::cout << std::endl;
				count = 0;
			}
		}
		cout << endl << endl;
	}
	else if ((cnt > 0 && cnt < 40))/*! Second condition checks if the iteration is less than 40 */
	{
		int count = 0;

		cout << "After eliminating " << cnt << "th person" << endl;
		cout << "---------------------------" << endl;

		for (auto it = names.begin(); it != names.end(); ++it)/*!Print out the remaining list of names */
		{
			cout << *it << " ";
			count++;
			if (count == NO_ITEMS)
			{
				std::cout << std::endl;
				count = 0;
			}
		}
		cout << endl << endl;
	}
	else/*! Last iteration only , there is 1 name in the list */
	{
		int count = 0;

		cout << "After eliminating " << cnt << "th person" << endl;
		cout << "---------------------------" << endl;

		for (auto it = names.begin(); it != names.end(); ++it)/*!Print the very last iteration, resulting in the last person alive */
		{
			cout << *it << " ";
			count++;
			if (count == NO_ITEMS)
			{
				std::cout << std::endl;
				count = 0;
			}
		}
		cout << endl << endl;
	}
}

/*!Main routine*/
#if 1
int main()
{
	list <string> names;/*! Empty list */
	int cnt = 0;/*! counts the number of iterations through each cycle */
	unsigned i = 0;/*! position of the name in the list*/
	args values;/*! Should work in terminal, since values in an object of args */

	//Before elimination
	init_vals(names, values);/*! Call to assign names to empty list*/
	print_list(names, cnt);/*! Call to print names of the list*/

	//Eliminations begin
	while (names.size() >= 1)/*! While the size of the list is greater than or equal to 1 */
	{
		cnt++;/*! increment the currrent iteration */

		if (cnt == 40)/*! If we are on the last iteration */
		{
			auto p = names.begin();/*! set the iterator to the begining of the list which is c7 */
			names.erase(p);/*! Erase c7 leaving D4 */
			print_list(names, cnt);/*! print the list ( only has D4 ) with count =40 the last iteration */
		}

		auto j = (i + values.M - 1) % names.size();/*!  If i (with initial value 0) indicates the position of a person in list L,
														then the statement: j = ( i + M – 1 ) % L.size ( ) returns the position
														of the M-th person from the position i. */

		auto p = names.begin(); /*!Since the argument to the erase()
								   function is an iterator, you can convert the index value j to an iterator by the
								   advance(p, j) function, where p = L.begin().*/
		advance(p, j);
		names.erase(p);

		if ((cnt) % values.K == 0)/*! If the iteration is dividible by 7 and its remainder is = 0 */
		{
			print_list(names, cnt);/*! Call print function */
		}

		i = j;/*! position of the person in the list is now equal the NEXT m-th person in the list that was not elimanated yet */

	}
	return 0;
}
#endif