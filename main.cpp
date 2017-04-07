#include <iostream>
#include "IntTree.hpp"

using namespace std;

int main() {

	IntTree myTree;
	myTree.insertValue(20);
	myTree.insertValue(30);
	myTree.insertValue(10);
	myTree.insertValue(40);
	myTree.insertValue(25);
	myTree.insertValue(15);
	myTree.insertValue(5);
	myTree.deleteValue(5);

	// boolalpha converts 1 and 0 to true and false
	cout << boolalpha << myTree.searchValue(30) << endl;
	cout << myTree.searchValue(31) << endl;
	
	cout << endl;

	cout << "(In Order):";
	myTree.InOrderPrint();
	cout << endl;

	cout << "(Pre Order):";
	myTree.PreOrderPrint();
	cout << endl;

	cout << "(Post Order):";
	myTree.PostOrderPrint();
	cout << endl;

	cout << endl << "done" << endl;
	return 0;

}