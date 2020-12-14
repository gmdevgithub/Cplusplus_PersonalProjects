/*
Giovanni J Moscato
Section: 003
Instructors: John Winans, Venkata Surya Vamsi Maddukuri
Date:9/27/2019
Assignment: Project 3

For this computer assignment, you are to write and implement an interactive C++
program to find and print all prime numbers, which are less than or equal to a given
value of n, using the algorithm known as the Sieve of Eratosthenes.
*/

#include "prog3.h"


/**
* This routine can be used to apply the Sieve of
* Eratosthenes algorithm
*
* A prime number p is an integer greater than 1 that is divisible only by 1 and p (itself).
* The algorithm begins by initializing a set container to contain all the integers in the
* range 2 to n. A loop makes multiple passes over the elements in the set, using successive
* integer key values 2, 3, 4, … Each pass “shakes free” nonprime numbers and lets them
* “filter through the sieve.” At the end, only the prime numbers remain.
*
* @param s empty set that was passed by reference
* @param n upper limit set by the user
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
void sieve(std::set < int >& s, int n)
{

	for (int i = 2; i <= n; ++i)
	{
		s.insert(i);//Fill the function up to limit n
	}

	for (int m = 2; m * m <= n; ++m)//Test all numbers m such that m * m <= n
	{
		for (int k = 2; k * m <= n; ++k)//k*m stores all the multiples of m 
		{
			s.erase(k*m);//Removing k*m from the set
		}
	}
	print_primes(s);
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
void print_primes(const std::set < int >& s)
{
	int count = 0;

	for (auto it = s.begin(); it != s.end(); it++)//Must use an iterator to iterate through associative container
	{
		count++;

		std::cout << std::setw(ITEM_W) << *it << " ";
		if (count == NO_ITEMS)
		{
			std::cout << std::endl;
			count = 0;
		}
	}
	std::cout << std::endl;
}


#if 1
int main()
{

	std::set < int > set1; //Empty set of int
	
	int limit;
	std::cout << "upper limit for the set of primes:";
	std::cin >> limit;//User input
	sieve(set1, limit);
		
	return 0;
}
#endif