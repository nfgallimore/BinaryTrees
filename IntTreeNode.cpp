class IntTreeNode
{
public:
	IntTreeNode(int theData, IntTreeNode* left, IntTreeNode* right)
	: data(theData), leftLink(left), rightLink(right){}
	
	// IntTreeNode(int theData, IntTreeNode* left, IntTreeNode* right)
	// {
	// 	data = theData;
	// 	leftLink = left;
	// 	rightLink = right;
	// }
private:
	int data;
	IntTreeNode *leftLink;
	IntTreeNode *rightLink;
};
void main(int argc, char** argv) {
	IntTreeNode a;
}

IntTreeNode *root;