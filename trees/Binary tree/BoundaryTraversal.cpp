// { Driver Code Starts
#include <iostream>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> printBoundary(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = printBoundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
vector<int> result;
void leftBoundary(Node *root)
{
    if(root == NULL)
        return ;
    
        if(root->left != NULL){
            result.push_back(root->data);
            leftBoundary(root->left);
        }
        else if(root->right != NULL) {
            result.push_back(root->data);
            leftBoundary(root->right);
        }
    
    // return result;
}

void rightBoundary(Node *root)
{
    if(root == NULL)
        return ;
    
        if(root->right) {
            rightBoundary(root->right);
            result.push_back(root->data);
        }
        else if(root->left) {
            rightBoundary(root->left);
            result.push_back(root->data);
        }
    
}
\
void leafNodes(Node *root)
{
    if(root == NULL)
        return ;
    
        leafNodes(root->left);
        if(!root->left && !root->right)
            result.push_back(root->data);
        leafNodes(root->right);
    
}
vector <int> printBoundary(Node *root)
{
    result.clear();
    result.push_back(root->data);
    leftBoundary(root->left);
    leafNodes(root);
    rightBoundary(root->right);
    return result;
}