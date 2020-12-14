/*
Giovanni J Moscato
Section: 003
Instructors: John Winans, Venkata Surya Vamsi Maddukuri
Date:11/4/2019
Assignment: Project 7

For this computer assignment, implement a derived class (as a template) to represent a
binary search tree. Since a binary search tree is a binary tree, implement your binary
search tree class from the base class of the binary tree that you implemented in your
previous assignment.
*/


#ifndef H_binSTree
#define H_binSTree

#include "binTree.h"





//binSTree is derived from binTree and has a access mode of type public
//A derived class can access all the non-private members of its base class.
//A derived class inherits all base class methods with the following exceptions 
//−Constructors, destructors and copy constructors of the base class.
//Overloaded operations and friend funcitons

//The key in each node must be greater than all keys found in the left
//subtree, and less than all keys in the right subtree.
//All subtrees must meet the same key criterion as above.



template < typename T >
class binSTree : public binTree < T >
{
public:
	//The insert() function inserts a node with the data value x in the tree.
	void insert(const T& x) // Takes a data value x
	{
		insert2(this->root, x);//Pass the pointer to the root along with the data value for x
	}
	
	bool search(const T& x) const // searches for leaf with value x  
	{
		return search2(this->root, x);//Look for this value x in the tree
	}
	bool remove(const T& x)// removes leaf with value x  
	{
		if (search(x) == true)//Look for this value x in the tree)
		{
			/*. The remove ( ) function first
			calls the search() function to determine the result of the search for a leaf with the data
			value x, and if the search is successful, then it calls the private version of the remove()
			function to remove the corresponding leaf from the tree and returns true; otherwise, it
			returns false*/
			remove2(this->root ,x);//Call the private version of remove to delete the actual leaf
			return true;
		}
		return false;
	}
private:
		/*!
		 insert2() is a void function that will fill the tree with nodes of values given by the vector in prog7.cc
		 \param ptr is a Node pointer to a root
		 \param val is value of current node
		*/
	void insert2(Node < T >*& ptr, const T&val) // private version of insert  takes 𝛰(log2 𝑛) time
	{
		if (ptr == nullptr)//If the pointer to the adress of the root is null
		{
			ptr = new Node <T>(val);//Point to a new node which holds the next value
		}
		else if (val < ptr->data)//If the value is less than the root of the curent tree/subtree
		{
			insert2(ptr->left, val);//Create a new node with that value on the left of the root call itself recursivley
		}
		else 
		{
			insert2(ptr->right, val);//Create a new node and insert it to the right
		}
	}
	/*!
	 search2() is a boolean function that will search for the a leaf of a tree.
	 \param ptr is a Node pointer to a root
	 \param val is value of current node
	*/
	bool search2(Node < T >* ptr, const T& val) const // private version of search  takes 𝛰(log2 𝑛) time
	{
		if (ptr == NULL)//If the pointer is pointing to Nothing 
		{
			return false;//Not a successful search
		}
		if (ptr->data == val)//If the node matches what we are looking for
		{
			if (leaf(ptr))//Check if the value we found is a leaf
			{
				return true;//We found it , sucessfull search
			}
			else
			{
				return false;//The search failed!
			}
		}
		else if (val < ptr->data)//Check left side of node
		{
			return search2(ptr->left, val);//Call search for the left of the current node
		}
		else
		{
			return search2(ptr->right, val);//Call search for the right side of current node
		}
	}
	/*!
	 remove2() is a boolean function that will delete a leaf of a tree.
	 \param ptr is a Node pointer to a root
	 \param val is value of current node

	 Error: I am getting an over flow error for this function! Causes program to crash 
	*/
	bool remove2(Node < T >*& ptr, const T& val) // private version of remove  takes 𝛰(log2 𝑛) time
	{
		Node <T>* current=nullptr;//Temp pointer for current node
		Node <T>* parent=nullptr;//Temp pointer for parent node
		current = ptr;//Set the current node to the pointer passed as an argument

		while (current != NULL)// while the current node is not empty
		{
			if (current->data == val)// Check if the current data is the leaf we want to delete
			{
				break;//If it is exit this while loop
			}
			else//If not set parent = current node 
			{
				parent = current;

				if (val > current->data)
				{
					current = current->right;//Set the current node to what its right pointer is pointing to 
				}
				else
				{
					current = current->left;//Set the current node to what its left pointer is pointing to 
				}
			}
		}

		if (current != NULL)// while the current node is not empty
		{
			if (parent->right == current)//If the parent node is pointing to the current node
			{
				parent->right = NULL;//Point it to null erasing the link between current
			}
			else
			{
				parent->left = NULL;//Point it to null erasing the link between current
			}

			delete current;//Delete the node from memory 
			current = NULL;//Reset the variable
		}
		return true;//Return 

	}
	/*!
	 leaf() is a boolean function that will check if a node is a leaf of a tree, it will return true or false.
	 \param root is a Node pointer to a root
	 Root is passed to the function by argument and is used as its param.
	 Function data is constant to avoid corruption
	*/
	bool leaf(Node < T >* root) const// checks if node is leaf
	{
		if (root->left == NULL && root->right == NULL)//If both pointers of this node point to NULL then it is a leaf 
		{
			return true;//Yes this is a leaf
		}
		false;//Nope thats not a leaf
	}
};



#endif