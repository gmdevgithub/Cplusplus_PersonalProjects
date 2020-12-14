/*
																Giovanni J Moscato
												Section: 003
												Instructors: John Winans, Venkata Surya Vamsi Maddukuri
												Date:9/10/2019
												Assignment: Project 1

												Info: Program to produce random int and store them in a vector.
*/

//Include the prog1 header file, should be the only included file in source file

#include "prog1.h"

//I wasnt sure if these were suppose to be macros.
//I originaly used #define but it seemed to be incorrect with the rand() function


//These are our global constants:
//Range
int LOW = 1;
int HIGH = 10000;
//Vector size
const int VEC_SIZE = 200;
//# of items to print
int NO_ITEMS = 12;
//# space to allocate for each number
int ITEM_W = 5;
//Seed
int SEED = 1;


//Routines:

//Subroutine 
//This routine generates VEC_SIZE integers and stores them in vector v.Initializes the random number generator(RNG) by calling -
//the function srand(SEED) with the seed value SEED = 1 and generates random integers by calling the function rand().

void genRndNums(std::vector <int> &rgen)
{
	//What I did before : srand((unsigned int)time(nullptr));
	// Had to convert time_ in 64 bit to unsigned int in 32 bit to work with my iterator.
	// Used a typecast to fix error: warning C4244: 'argument' : conversion from 'time_t' to 'unsigned int', possible loss of data"
	

	//Instead we are seeding it to 1 and not time.
	srand(SEED);

	for (int i = 0; i < VEC_SIZE; ++i)
	{
		//Generate random int
		int random = rand() % (HIGH - LOW + 1) + LOW;
		//Set each space in memory to a random number
		rgen.at(i) = random;
	}
	//Sort the random numbers with iterator range begin and end. ( Different from front & back**  )
	std::sort(rgen.begin(), rgen.end());
}


//Subroutine
//This routine displays the contents of vector v on stdout, printing exactly NO_ITEMS = 12 numbers on a single line, except
//perhaps the last line.The sorted numbers need to be properly aligned on the output.For each number, allocate ITEM_W = 5 spaces on stdout.

void printVec(const std::vector <int> &rgen)
{

	//This seems to be the best solution to print a vector with 5 spaces and 12 numbers per line.
	//The int must start at 1 because of the pre increment
	//Index i must be an unsigned int to work with vector size due to rand()
	for (unsigned int i = 1; i <= rgen.size(); ++i)
	{
		//output each value in the vector starting at rgen.at(0)
		std::cout << std::setw(5) << rgen.at(i - 1);

		//If the current index value is divisible by 12 and its remainder is 0, end the line.
		if (i % 12 == 0)
		{
			std::cout << std::endl;
		}

	}


	//I tried to do this as well but it went out of bounds?
	//unsigned int i = 0;
	/*while( i <= rgen.size())
	{
		for (int count = 0; count < NO_ITEMS; count++)
		{
			std::cout << std::setw(ITEM_W) << rgen.at(i);
		
			++i;
		}

		std::cout << std::endl;
	}*/

}

//Main routine 
int main()
{
	//Created a vector with size of VEC_SIZE
	//The vector is passed by reference so we can manipulate its data directly in each routine.
	std::vector<int> rgen(VEC_SIZE);
	//Generate number method
	genRndNums(rgen);
	//Print number method
	printVec(rgen);

}
