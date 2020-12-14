
#ifndef prog4_H
#define prog4_H

//Macros
#define NO_ITEMS 3
#define ITEM_W 16

//#includes
#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>
#include <string>
#include <ctype.h>

//Namespace
using namespace std;

//Declarations
void get_words(map < string, int >& wordmap);
void print_words(const map < string, int >& wordmap);
void clean_entry(const string& origial, string& dirtyWord);
void convert_to_low(char& lowerCase);
bool isNumFunction(const char& firstLetter);
bool is_not_alnum(const char& punctuation);


#endif // !prog4_H
