#include "IntTree.hpp"
#include <iostream>

IntTree::~IntTree() {

}

void IntTree::insertValue(int val) { // insert a value to the tree


// If root node is null
	// assign new node address to root node
// else create a temp root pointer for the subtree, intitialized to root first
	// while childnode is not null
	// Mark: if inserted value smaller than root value
		// insert to left
		// if left child is null: attach new node
		// set temp root pointer to the left child node, go back to Mark
	// else
		// insert to right
		// if right child is null: attach new node
		// set temp root pointer to right child node: go back to Mark

	TreeNode * newNodeAddress = new TreeNode(val);
	if (rootNodeAddress == nullptr) {
		rootNodeAddress = newNodeAddress;
		return;
	}
	TreeNode * subTreeRootAddress = rootNodeAddress; // initialize it to the root
	while (true) {
		if (val < subTreeRootAddress->data) {
			// insert to the left
			if (subTreeRootAddress->leftChildNodeAddress == nullptr) {
				// left child is empty, just simply attach to the left
				subTreeRootAddress->leftChildNodeAddress = newNodeAddress;
				//std::cout << "left " << subTreeRootAddress->data << std::endl;
				return;
			}
			else {
				// treat the left child node as a new sub tree and go over the procedure again
				subTreeRootAddress = subTreeRootAddress->leftChildNodeAddress;
				/* in a loop if you say continue it will go to start of loop */
				continue;

			}
		}
		else {
			// insert to the right
			if (subTreeRootAddress->rightChildNodeAddress == nullptr) {
				// right child is empty, just simply attach to the riht
				subTreeRootAddress->rightChildNodeAddress = newNodeAddress;
				//std::cout << "right " << subTreeRootAddress->data << std::endl;
				return;
			}
			else {
				// treat the right child node as a new sub tree and go over the procedure again
				subTreeRootAddress = subTreeRootAddress->rightChildNodeAddress;
			}
		}
	}
}

bool IntTree::searchValue(int val) { // search for a value in the tree
	TreeNode* subTreeNodeAddress = rootNodeAddress;
	while (true) {
		if (subTreeNodeAddress == nullptr) {
			return false;
		}
		if (val == subTreeNodeAddress->data) {
			return true;
		}
		else {
			if (val < subTreeNodeAddress->data) {
				// search the left sub tree
				subTreeNodeAddress = subTreeNodeAddress->leftChildNodeAddress;
			}
			else {
				// search the right sub tree
				subTreeNodeAddress = subTreeNodeAddress->rightChildNodeAddress;
			}
		}
	}
}
void IntTree::InOrderPrint(TreeNode* subTreeRootAddress) { // left me right
	if (subTreeRootAddress == nullptr) return;
	InOrderPrint(subTreeRootAddress->leftChildNodeAddress); // print the left sub tree
	std::cout << subTreeRootAddress->data << " "; // print me
	InOrderPrint(subTreeRootAddress->rightChildNodeAddress); // print the right sub tree
}
bool IntTree::deleteValue(int val) { // delete a value in the tree
	TreeNode* parentNodeAddress = nullptr;
	TreeNode* currentNodeAddress = rootNodeAddress;
	while (true) {
		if (currentNodeAddress == nullptr) {
			return false;
		}
		if (val == currentNodeAddress->data) {

			// we are going to delete currentNode
			if (parentNodeAddress == nullptr) {
				// the one to delete is the root node
				delete parentNodeAddress;
				return true;
			}
			else {
				// if both child nodes are null
				if (currentNodeAddress->leftChildNodeAddress == nullptr && currentNodeAddress->rightChildNodeAddress == nullptr) {
					if (currentNodeAddress->data < parentNodeAddress->data) { // current is smaller than the left
						parentNodeAddress->leftChildNodeAddress = nullptr;
					}
					else {
						parentNodeAddress->rightChildNodeAddress = nullptr;
					}
					delete currentNodeAddress;
					return true;
				}
				else if (currentNodeAddress->leftChildNodeAddress != nullptr && currentNodeAddress->rightChildNodeAddress == nullptr) {
					parentNodeAddress->leftChildNodeAddress = currentNodeAddress->leftChildNodeAddress;
				}
				else if (currentNodeAddress->leftChildNodeAddress == nullptr && currentNodeAddress->rightChildNodeAddress != nullptr) {
					parentNodeAddress->rightChildNodeAddress = currentNodeAddress->leftChildNodeAddress;
				}
				else {
					// have both left and right child
					parentNodeAddress->leftChildNodeAddress = currentNodeAddress->leftChildNodeAddress;
					parentNodeAddress->rightChildNodeAddress = currentNodeAddress->rightChildNodeAddress;
				}
			}
		}
		else {
			if (val < currentNodeAddress->data) {
				// search the left sub tree
				currentNodeAddress = currentNodeAddress->leftChildNodeAddress;
			}
			else {
				// search the right sub tree
				currentNodeAddress = currentNodeAddress->rightChildNodeAddress;
			}
		}
	}
}

void IntTree::InOrderPrint() { // print the whole tree with InOrder
	InOrderPrint(rootNodeAddress);
}
void IntTree::PreOrderPrint(TreeNode * subTreeRootAddress) { // print the whole tree with PreOrder // me left right
	if (subTreeRootAddress == nullptr) return;
	std::cout << subTreeRootAddress->data << " "; // print me
	PreOrderPrint(subTreeRootAddress->leftChildNodeAddress); // print the left sub tree
	PreOrderPrint(subTreeRootAddress->rightChildNodeAddress); // print the right sub tree
}
void IntTree::PreOrderPrint() { // print the whole tree with InOrder
	PreOrderPrint(rootNodeAddress);
}
void IntTree::PostOrderPrint(TreeNode * subTreeRootAddress) { // print the whole tree with PreOrder // left right me
	if (subTreeRootAddress == nullptr) return;
	PostOrderPrint(subTreeRootAddress->leftChildNodeAddress); // print the left sub tree
	PostOrderPrint(subTreeRootAddress->rightChildNodeAddress); // print the right sub tree
	std::cout << subTreeRootAddress->data << " "; // print me
}
void IntTree::PostOrderPrint() { // print the whole tree with PostOrder
	PostOrderPrint(rootNodeAddress);
}
