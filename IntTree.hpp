#include <iostream>
class IntTree
{
	class TreeNode
	{
	public:
		int data;
		TreeNode* leftChildNodeAddress, *rightChildNodeAddress;
		TreeNode(int val) {
			data = val;
			leftChildNodeAddress = nullptr;
			rightChildNodeAddress = nullptr;
		}
	};
	TreeNode *rootNodeAddress;
	// left first, right second, me last
	// for "in order" printing of binary tree

	void InOrderPrint(TreeNode * subTreeRootAddress); // recursive function to print hte node values under that sub tree root address
	void PreOrderPrint(TreeNode * subTreeRootAddress); // recursive function to print hte node values under that sub tree root address
	void PostOrderPrint(TreeNode * subTreeRootAddress); // recursive function to print hte node values under that sub tree root address

public:
	IntTree() {rootNodeAddress = nullptr;} // default constructor
	~IntTree(); // destructor to remove all dynamically allocated node memory
	void insertValue(int); // insert a value to the tree
	bool searchValue(int); // search a value in the tree, return true if found, false if not
	bool deleteValue(int); // delete a value in the tree, return true if found, false if not
	void InOrderPrint(); // print the whole tree with InOrder
	void PreOrderPrint(); // print the whole tree with PreOrder (print me first, then print the left, then print the right)
	void PostOrderPrint(); // print the whole tree with PostOrder 
};