// C++ implementation to print the path from root
// to a given node in a binary tree
#include<iostream>
#include<vector>
using namespace std;

// structure of a node of binary tree
struct Node
{
	int data;
	Node *left, *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* getNode(int data)
{
	struct Node *newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

bool hasPath(Node *root, vector<int> &arr, int data)
{
    if(!root)
        return false;
    if(root->data == data)
    {
        arr.push_back(root->data);
        return true;
    }
    if(hasPath(root->left, arr, data)) {
        arr.push_back(root->data);
        return true;
    }
    if(hasPath(root->right, arr, data)){
        arr.push_back(root->data);
        return true;
    }
    // arr.pop_back();
    return false;
}

	
	
	
	

void printPath(Node *root, int x)
{
	// vector to store the path
	vector<int> arr;
	
	// if required node 'x' is present
	// then print the path
	if (hasPath(root, arr, x))
	{
		for (int i=0; i<arr.size()-1; i++)	
			cout << arr[i] << "->";
		cout << arr[arr.size() - 1];	
	}
	
	// 'x' is not present in the binary tree
	else
		cout << "No Path";
}

// Driver program to test above
int main()
{
	// binary tree formation
	struct Node *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	root->right->left = getNode(6);
	root->right->right = getNode(7);
		
	int x = 5;
	printPath(root, x);
	return 0;
}
