#include<iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    node(int n) {
        data = n;
        left = NULL;
        right = NULL;
    }
};

node* constructBST(vector<int> preOrder, int n, int low, int high) {
    node *root;   
    if (low > high || n == 0)
        return root;
        
}

int main()
{
    vector<int> preOrder;
    int n = 0, a = 0;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a;
        preOrder.push_back(a);
    }
    constructBST(preOrder, n, 0, n);


}