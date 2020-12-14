/*
Giovanni J Moscato
Section: 003
Instructors: John Winans, Venkata Surya Vamsi Maddukuri
Date:11/17/2019
Assignment: Project 8

For this computer assignment, you are to write a C++ program to sort items in several
input files, using the heapsort technique.
*/


#include "/home/cs340/progs/19f/p8/prog8.h" /*! Includes */



/*!
	 getlist() is a template function that will take the vector and a path as its parameters. It then uses <fstream> to read data from a file
	 into a variable of type T. It will take any type of data and then push it into the vector as long as reading from the file.

	 \param v is a empty vector defined in main()
	 \param path is the path name of the file we are looking for to import data from

	 Error: If the file can not be opened or is empty it will output an error message
*/
template < typename T >
void get_list(vector < T >& v, const char* path)
{
	if (!v.empty())
	{
		v.clear();
	}


	//Takes v[1-3] and D[1-3] and should fill the vector by reference with the data

	//Open file and check for errors 
	T line;/*! Takes any values from macro*/

	
	ifstream myfile(path);/*! Open pathname */

	//If the file is open
	if (myfile.is_open())
	{
		//While reading from file
		while (myfile >> line) /*! Get all numbers*/
		{
			//Fill the vector with data
			v.push_back(line);/*! Vector is now filled with data from macro pathname */
		}
		myfile.close();/*! Close the file */

		cout << endl;
	}
	else
	{
		cout << "Unable to open file";
	}

}

/*!
	 construct_heap() is a template function that will simply construct and then sort a heap.
	
	 \param v is a vector that we filled with data from a pathname
	 \param pred is the uniary predicate that we defined in main(), it will decide if the heap is sorted in ascending order or descending

*/

template < typename T, typename P >
void construct_heap(vector < T >& v, P pred)
{
	//Construct heap
	//Call STL:make_heap()
	make_heap(v.begin(), v.end(), pred);/*! Rearranges the elements in the range [first,last) in such a way that they form a heap. */

	//Sort the STL:sort_heap()
	sort_heap(v.begin(), v.end(),pred);/*! Sorts the elements in the heap range [first,last) into ascending order. Descending if the predicate is
	greater than */
}

///From header file 
/*!
	 printlist() is a constructor definition

	 \param s defined in header file
	 \param w defined in header file
	 \param l defined in header file
	 \param c defined in header file

*/
template < typename T > 
print_list < T >::print_list(const unsigned& s, const unsigned& w, const unsigned& l, const unsigned& c)
{
	sz = s;/*! Size of the element in heap */
	wid = w;/*! Width of the element in heap */
	len = l;/*! Length of elements to be printed */
	cnt = c;/*! Count how many elements have been printed from the heap */

}

/*!
	 operator() is an overloaded operator in which we change the standard output of each element and its format

	 \param x represents each element in the heap
	 
*/

template < typename T > 
void print_list < T > :: operator ( ) (const T& x)
{
	//Format the standard output
	std::cout.width(wid);
	std::cout.precision(2);
	cout << fixed << showpoint;
	
	for (unsigned int i = 0; i < 1; ++i)/*! For each element in the vector of range [first, last) */
	{
		//If the count it at 15 then output a newline
		if (cnt == len)/*! Len is set to 15 so the count will stop at 15 elements */
		{
			cout << endl;
			cnt = 0;/*! Reset the counter */
		}

		cout << x;/*! Output each element in the vector that was made into a heap form */
		cnt++;/*! Increment the counter */
	}
	
}




int main()
{
	
	//Vectors contatining heap data
	vector < int >    v1;   // heap of integers
	vector < float >  v2;   // heap of floating-pt nums
	vector < string > v3;   // heap of strings
	// print header message
	cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";
	cout << endl;

	
	// first heap
	cout << "first heap - ascending order:\n\n";//Just an output message
	get_list(v1, D1);//Passes a vector that is empty and a macro value 
	construct_heap(v1, less < int >());//Call construct heap 
	print_list < int > print1(v1.size(), INT_SZ, INT_LN);
	for_each(v1.begin(), v1.end(), print1);//Applies function fn to each of the elements in the range [first,last).
	cout << endl;
	
	cout << endl;
	cout << "first heap - descending order:\n\n";
	get_list(v1, D1);
	construct_heap(v1, greater < int >());
	for_each(v1.begin(), v1.end(), print1);
	cout << endl;
	

	// second heap

	cout << endl;
	cout << "second heap - ascending order:\n\n";
	get_list(v2, D2);
	construct_heap(v2, less < float >());
	print_list < float > print2(v2.size(), FLT_SZ, FLT_LN);
	for_each(v2.begin(), v2.end(), print2);
	cout << endl;

	cout << endl;
	cout << "second heap - descending order:\n\n";
	get_list(v2, D2);
	construct_heap(v2, greater < float >());
	for_each(v2.begin(), v2.end(), print2);
	cout << endl;

	// third heap

	cout << endl;
	cout << "third heap - ascending order:\n\n";
	get_list(v3, D3);
	construct_heap(v3, less < string >());
	print_list < string > print3(v3.size(), STR_SZ, STR_LN);
	for_each(v3.begin(), v3.end(), print3);
	cout << endl;

	cout << endl;
	cout << "third heap - descending order:\n\n";
	get_list(v3, D3);
	construct_heap(v3, greater < string >());
	for_each(v3.begin(), v3.end(), print3);
	cout << endl;
	cout << endl;

	// print termination message
	cout << "\t\t\t*** end of program execution ***\n\n";


	return 0;
}




