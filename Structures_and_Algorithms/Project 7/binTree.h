/*
Giovanni J Moscato
Section: 003
Instructors: John Winans, Venkata Surya Vamsi Maddukuri
Date:10/24/2019
Assignment: Project 6

For this computer assignment, you are to write a C++ program to implement a class for binary
trees. To deal with variety of data types, implement this class as a template.
*/
#ifndef H_binTree
#define H_binTree


#include "/home/cs340/progs/19f/p7/Node.h"



// FOR TERMINAL USE DONT FORGET TO IMPLEMENT THIS
//#include "/home/cs340/progs/19f/p6/Node.h"

typedef enum { left_side, right_side } SIDE;//Define two enum types
SIDE rnd() { return rand() % 2 ? right_side : left_side; } //Used to decide random placement of Nodes, either left or right side


template < class T >
class binTree
{
	//Public functions can be accessed by any file including the header
public:
	//Sets the root of the tree to NULL 
	//Will return height of the tree
	binTree() // default constructor
	{
		root = nullptr;//set the root
	}
	unsigned size() const
	{
		return sizeP(root);
	}
	unsigned height() const//A public function that prog6.cc can access
	{
		// returns height of tree
		return heightP(root); // Call private member heightP and pass the root as an argument 
	}
	//A virtual member is a member function that can be redefined in a derived class, while preserving its calling properties through references.
	virtual void insert(const T& x)
	{
		// Inserts node in tree through the private function insertP by passing a root and the data value x
		insertP(root, x);// Data value X contains vector values
	}
	void inorder(void(*print) (const T&))
	{	
		// Calls in order transversal of the tree 
		inOrderP(root, print);// Pass the root again and the argument taken as the entire print function defined in main
	}


protected:
	Node < T >* root; /*!< root of tree must not be changed by the source file but only functions with access to the root */

private:
	/*!
	 heightP() is a private function which is called by height and will recursivly call itself.
	 \param nextnode holds the root.
	 Root is passed to the function by argument and is used as its param.
	 Function data is constant to avoid corruption
	*/
	unsigned sizeP(Node < T >*ptr) const
	{
		if (ptr != 0) // if not empty
		{
			return 1 + sizeP(ptr->left) + sizeP(ptr->right);
		}
		else
		{
			return 0; // emtpy tree
		}
	}
	unsigned heightP(Node < T >* nextnode) const
	{
		if (!nextnode)
		{//if null, height = 0
			return 0;
		}
		else
		{
			// 9 nodes + 1 for the root 
			return 1 + max(heightP(nextnode->left), heightP(nextnode->right)); //Finds the trees height by returning the largest value for left/right
		}
	}
	void insertP(Node < T >*& nextnode, const T& x)
	{
		/*!
		 insertP() is a private function which is called by insert and will recursivly call itself.
		 \param nextnode is a pointer to a reference of the next node.
		 \param x holds the data which contains the values of the vector from prog6.cc
		*/
		if (nextnode == 0)//If there is a new tree with root = 0
		{
			/* if the tree is empty, then the new node will be the root of the tree with the value x */

			Node <T> * newNode; // Create a node pointer from the NODE class of type T
			newNode = new Node <T>(x);//Allocate memory for the new node with given vector data x
			nextnode = newNode;//now the second node acts as a new "root" but is actualy a child of the first root
		}
		else
		{
			// Private function is only able to be called from other class functions
			if (rnd() == right_side)
			{
				// Recursivly call private function insertP and place data x in each node to the right
				insertP(nextnode->right, x);
			}
			else
			{
				// Recursivly call private function insertP and place data x in each node to the left
				insertP(nextnode->left, x);
			}
		}
	
	
	}
	/*!
	inOrderP() is a private function which is called by inOrder and will recursivly call itself.
	\param nextnode is a pointer to the next node.
	\param print is an argument that is passed to inOrder from printvals which was passed to inOderP
	*/
	void inOrderP(Node < T >* nextnode, void(*print)(const T&))// Will perform inOrder transveral of the tree 
	{
		// If the root is not empty then 
		if (nextnode != nullptr)
		{
			//Recursivly call private memeber funciton inOrderP which then prints each node starting from the left back to the root
			inOrderP(nextnode->left, print);
			//Root then prints itself in order 
			print(nextnode->data);
			//Recursivly call private memeber funciton inOrderP which then prints each node starting from the right back to the root 
			//This ends when it reaches the root again and root has finished both of its childrens transverals.
			inOrderP(nextnode->right, print);
		}
	}
};


#endif
