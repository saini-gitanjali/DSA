// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* even=NULL;
Node* e=NULL;
Node* odd=NULL;
Node* o=NULL;

while(head!=NULL){
if(head->data%2==0){
if(even==NULL){
even=head;
e=head;
}
else{
e->next=head;
e=e->next;
}
}
else if(head->data%2!=0){
if(odd==NULL){
odd=head;
o=head;
}
else{
o->next=head;
o=o->next;
}
}
head=head->next;
}
if(even!=NULL){e->next=odd;}
if(odd!=NULL){o->next=NULL;}
if(even==NULL)return odd;
return even;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* even=NULL;
Node* e=NULL;
Node* odd=NULL;
Node* o=NULL;

while(head!=NULL){
if(head->data%2==0){
if(even==NULL){
even=head;
e=head;
}
else{
e->next=head;
e=e->next;
}
}
else if(head->data%2!=0){
if(odd==NULL){
odd=head;
o=head;
}
else{
o->next=head;
o=o->next;
}
}
head=head->next;
}
if(even!=NULL){e->next=odd;}
if(odd!=NULL){o->next=NULL;}
if(even==NULL)return odd;
return even;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends