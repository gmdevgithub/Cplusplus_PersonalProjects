/*
Giovanni J Moscato
Section: 003
Instructors: John Winans, Venkata Surya Vamsi Maddukuri
Date:11/30/2019
Assignment: Project 9

For this computer assignment, you are to write a C++ program to create, search, print,
and sort an item inventory.
*/

//Includes:
#include "/home/cs340/progs/19f/p9/hTable.h"

#ifndef H_TABLE
#define H_TABLE

/*!
	 HT() is a constructor for the hash table. It creates an empty table and sets the table to a default size of the table to TBL_SZ

	 \param s is the value of TBL_SZ in which we use to resize the hash table and pointer vector. The private memeber hsize is also altered.
	

	 Error: The function should only create and resize and EMPTY table or vector. 
*/
HT::HT(const unsigned& s) : hsize(TBL_SZ)/*! hsize is now set to TBL_SZ via a constructor list */
{
	hTable.resize(s);/*! Hash table is now resized to 0-30 */
	pTable.resize(s);/*! Pointer vector is now resized to 0-30 */
}
/*!
	 ~HT() is a destructor for the hash table. It will delete and empty the tables from memory.

	 Error: The function should should not be called it is for memory managment
*/
HT::~HT()
{
	//delete [] hTable;
	//delete [] pTable;
}

/*!
	 HT::insert() is a public member function of class HT. It is type void so it will return nothing. The function takes an entry by reference
	 and will insert the entry into the hash table (htable). If there is a collision the entry will be kept at the begging of the internal list.
	 As each entry is inserted into the table it will print the index value of the entry and insert the adress of that entry into the pointer 
	 vector as ptable. 


	 \param e is the entry that is passed by value. We want to keep it constant to avoid data corruption! The object e holds the values given to 
	 it by prog9.cc and was also passed by prog9.cc

	 find_if() Returns an iterator to the first element in the range [first,last) for which pred returns true. 
			   If no such element is found, the function returns last.

	 l.cend() returns a const_iterator pointing to the past-the-end element in the container.



	 Error: There should be no duplicates?
*/
void HT::insert(const Entry& e)
{
	string keyval = "";

	int hashVal = hash(e.key);/*! hashval is an integer created by the hash function which takes the value of entry-> key which is determined in 
							  prog9.cc and then passed to hash. This value should be an integer between 0-30 */

	//Duplicate Keys not allowed

	// Step1: we need to check if the values match
	/*To check if the record e is already in the hash table, you can use the function
	find_if() in the STL.To compare the key of the record e with the keys of the
	elements in the list container, list < Entry >& l = hTable[i], in hash table position i,
	you can use either a predicate or a lambda for the compare component of the
	find_if() function.If the item is a new item, then the find_if() function returns
	l.cend().*/


	list < Entry >& l = hTable[hashVal];/*! creates a new reference to the list inside the hash table, this is set equal to the value at position i */

	if(find_if(l.begin(), l.end(), [keyval](const Entry &e) {return keyval == e.key; }) != l.cend())
			/*!lambda expression to allow us write an inline function which can be used for
			   short snippets of code that are not going to be reuse and not worth naming.*/
	{
		cout << "Key, not inserted ";
		cout << endl;//If there is already a key print an error message 
	}
	else
	{
		// Step2: it prints the index value of the inserted record in the hash table
		l.push_front(e);
	
		Entry* pitem = new Entry(e.key, e.desc, e.num);/*! Item is now pointing to the entrys in hTable*/
		pTable.push_back(pitem); /*! Now push the adress of the entrys into the pointer vector*/
			
		cout << " Item: " << hashVal << endl;/*! print our item at index i */
	}
}

/*!
	 HT::search() is a public member function of class HT. It is type void so it will return nothing. The function searches the hash table to see
	 if the key values match. If they do we print the values in the structure at that point 

	 \param s is the entry that is passed by value. We want to keep it constant to avoid data corruption! The object e holds the values given to
	 it by prog9.cc and was also passed by prog9.cc

	 find_if() Returns an iterator to the first element in the range [first,last) for which pred returns true.
			   If no such element is found, the function returns last.

	 l.cend() returns a const_iterator pointing to the past-the-end element in the container.



	 Error: prints error message
*/
void HT::search(const string& s)
{
	int hashVal = hash(s); /*! New key value for index i */
	list <Entry>& l = hTable[hashVal];/*! Create a new list object */

	auto it = find_if(l.begin(), l.end(), [s](Entry e) {return s == e.key;});
	/*! Lambda to check again if the keys match! Find_if will return an iterator to the begining of the
	hTable vector which will be set to our iterator */
	
	//Step1: you can use the find_if() function from in the STL to search for a record in the hash table.
	if (it != l.cend())
	{
		cout << " Number: " << it->key << " Desc: " << it->desc;
		cout << endl;/*! Output the number and desc, the iterator uses the -> operator to
						 acess the values within the structure at each element */
	}
	else
	{
		//Else print an error message!
		cout << "NO ITEM" << endl;
	}
}
/*!
	 HT::hTable_print() is a public member function of class HT. It is type void so it will return nothing. This public function prints the subscript and the contents of
						all (and only) the active records in the hash table

	 Error: none
*/
void HT::hTable_print()
{
	// prints the subscript and the contents of all(and only) the active records in the hash table.

	Entry item;/*! make object for item */
	
	for (unsigned int i = 0; i < hsize; i++)/*! Outer for loop will set the list object to each tables index */
	{
		list <Entry>& l = hTable[i];/*! Create another list object that is set to hTable index */

		for (auto it = l.begin(); it != l.end(); it++)/*! Inner for loop will print the index value as well as the 
													  value of each entry that the iterator points to in the structure*/
		{
			cout << i << ": ";
			cout << it->key << " Desc: ";
			cout << it->desc << " Num: ";
			cout << it->num;
			cout << endl;/*! Output */
		}
	}

}

/*!
	 HT::pTable_print() This public function prints the contents of all (and only) the
						active records in the hash table. Since the records need to be printed in
						alphabetical order with their key values, this function first sort the elements of
						the pointer table using the sort ( ) function in the STL. The cmp component for
						sorting, bool cmp ( Entry* p, Entry* q ), returns true if the key of the item in location
						p comes before the item in location q in alphabetical order.

	 Error: none
*/
void HT::pTable_print()
{
	
	// Step1: The cmp component for sorting, bool cmp(Entry* p, Entry* q), returns true if the key of the item in location 
	//p comes before the item in location q in alphabetical order.

	//[](Entry* p, Entry* q) {return p->key < q->key; } lambda implementation for Entry pointers p and q

	// Step2:  this function first sort the elements of the pointer table using the sort() function in the STL.
	sort(pTable.begin(), pTable.end(), [](Entry* p, Entry* q) {return p->key < q->key; });	
	/*! The compare function will return true if q entry is greater than p entry
		which is what points to those entry's*/
	
	for (auto it = pTable.begin(); it != pTable.end(); it++)/*! Simply print the ptable! */
	{
		cout << (*it)->key << " Num: " << (*it)->num << " Desc: " << (*it)->desc;
		cout << endl;/*! Because we are now printing the adress of these entry's
						 we have to dereference the values that our iterator points to! */
	}
}


#endif