/*
Giovanni J Moscato
Section: 003
Instructors: John Winans, Venkata Surya Vamsi Maddukuri
Date:10/7/2019
Assignment: Project 4

For this computer assignment, you are to write and implement an interactive C++
program to scan and process a stream of words of a plain text.
*/


#include "prog4.h"

//Predicates:

/**
* Is a predicate that returns true if a character is alphanumeric
*
* @param firstLetter: Takes each word by ref.
*
* @return is true
*
* @note uses isalnum(). Each word is passed to isalnum() to decide if it is a alphanumeric character or not
*
* @warning none
*
* @bug none
*****************************************************************************/
bool isNumFunction(const char& firstLetter)
{
	return (isalnum(firstLetter) > 0);
}

/**
* Is a predicate that returns true if a character is NOT alphanumeric
*
* @param punctuation: Takes each word by ref.
*
* @return is true
*
* @note uses isalnum(). Each word is passed to isalnum() to decide if it is a alphanumeric character or not
*
* @warning 'operation' : unsafe use of type 'bool' in operation
*
* @bug Fixed bug involving the error described above, fixed by using two boolean variables.
*****************************************************************************/
bool is_not_alnum(const char& punctuation)
{
	bool value = (!isalnum(punctuation));// fixes error invloving 'operation' : unsafe use of type 'bool' in operation
	bool zero = false;

	return (value > zero);// The > operation had to work on two boolean values not one bool and one int.
}

/**
* Converts all words to lowercase, including cleaned words by using tolower()
*
* @param upperCase: Parameter holds original uppercase/normal word. 
*
* @return is void
*
* @note uses tolower()
*
* @warning none
*
* @bug none
*****************************************************************************/
void convert_to_low(char& upperCase)
{
	upperCase = tolower(upperCase);
	return;
}

/**
* It gets a word from the input stream and removes its punctuation marks
*
* Takes input from standard cin until the user uses a command to end it. All empty strings are ignored.
* Any strings that contain punctuation are sent to the cleanword fucntion and only cleaned words are added to the map
*
* @param wordmap: Starts as an empty map, cleaned words are added to it changing the original map by ref. 
*
* @return is void
*
* @note Uses two strings to keep the original and cleaned words seperated
*
* @warning Must use command line to stop cin input stream. 
* 
* @bug Will treat numbers as a string, numbers typed will count as words
*****************************************************************************/
void get_words(std::map <std::string, int>& wordmap)
{
	std::string original;
	std::string cleanWord;

	while (std::cin) 
	{
		cin >> original; 
		if (original.length() == 0)// Ignore empty strings
		{
			continue;
		}
		else
		{
			clean_entry(original, cleanWord); // calls another subroutine

			if (cleanWord.size() > 0)
			{
				wordmap[cleanWord]++; // add to set if > 0
			}
		}
	}
}



/**
* It cleans a word from its punctuation marks. 
* The first argument is the original word in the input
*
* @param original: Original word from the getword()function
*
* @param dirtyWord: word that must be cleaned of its puncuation marks
*
* @return is void
*
* @note uses findif(), substr(), and for_each() member functions. 
* Findif() and for_each() use predicates defined above. 
*
* @warning predicates use the range given, it must be half open. Predicate functions perform on each element of wordmap
*
* @bug on windows iterator may be affected from control Z command.
*****************************************************************************/
void clean_entry(const std::string& original, std::string& dirtyWord)
{
	
	auto first = original.begin();//Initialize an index variable to indicate the first character in a word
	auto second = original.begin();

	//Uses form : it = find_if(myvector.begin(), myvector.end(), IsOdd); IsOdd is first predicate
	first = find_if(original.begin(), original.end(), isNumFunction);//returns true if a character is alphanumeric		
	
	second = find_if(original.begin(), original.end(), is_not_alnum);//returns true if the character is non - alphanumeric	

	//{unaffectedword}
	// ^ both iterator positions

	//{affectedword}
	// ^ first iterator position is here

	//{affectedword }
	//             ^ second iterator position just after last char

	std::size_t pos = first - original.begin();//Copy the word from the first alphanumeric character until the last one to another string.
	std::size_t len = second - first;
														
	dirtyWord = original.substr(pos, len);//The substring is the portion of the object that starts at character position pos and spans len characters
	
	for_each(dirtyWord.begin(), dirtyWord.end(), convert_to_low);// You can convert a character to lowercase by the C library function : tolower()
}

/**
* It prints the final list of words and their frequencies.
* It also prints the number of nonempty words and the number of distinct words
* in the input stream
*
* @param wordmap: const wordmap is now a unchangeable, cleaned map of the words originally given from getwords()function
*
* @return is void
*
* @note uses left spacing
*
* @warning must use a this pointer -> for iterating through a map. First refers to the string, and second refers to it's index. 
*
* @bug windows will output the last word in wordmap 1 times to many, possible logic error or system error.
*****************************************************************************/
void print_words(const std::map <std::string, int>& wordmap)
{
	int count = 0;
	int words = 0;

	for (auto i = wordmap.begin(); i != wordmap.end(); i++)
	{
		std::cout << std::left << std::setw(ITEM_W) << i->first << "= " << std::setw(5) << i->second;//First refers to the string,
																									 //and second refers to it's index. 
		count++;
		words = words + (i->second);//Add the index value to the # of words per word.

		if (count == NO_ITEMS)
		{
			std::cout << std::endl; 
			count = 0;
		}
	}
	std::cout << std::endl << "Number of non-empty words: " << words << std::endl;
	std::cout << "Number of distinct words: " << wordmap.size() << std::endl;
}


#if 1
int main()
{
	std::map <std::string, int> wordmap;//Just an empty map

	//Subroutines:
	get_words(wordmap);
	print_words(wordmap);
	
	return 0;
}
#endif