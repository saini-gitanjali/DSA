#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void huffman(string code, Node *t)
{
    if(t->left==NULL && t->right==NULL){
        cout<<code<<" ";
        return;
    }
    huffman(code+"0",t->left);
    huffman(code+"1",t->right);
    
}

int main()
 {
    string str;
    int t;
    priority_queue<Node*, vector<Node*>, greater<int>> pq;
    cin>>t;
  while(--t)
    {
        cin>>str;
        int n=str.length();
        int freq[n];
        for(int i=0; i<str.length(); i++)
        {
            cin>>freq[i];
            Node* node  = new Node(freq[i]);
            pq.push(node);
        }
        while(pq.size()!=1)
        {
            int n = pq.top();
            pq.pop();
            int m = pq.top();
            pq.pop();
            Node * temp = new Node(n->data+m->data);
            temp->left = n;
            temp->right = m;
            pq.push(temp);
        }
        Node *root = pq.top();
        string code="";
        huffman(code,root);
        cout<<endl;
    }
   
	return 0;
}
