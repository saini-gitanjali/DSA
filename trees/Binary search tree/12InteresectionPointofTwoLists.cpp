// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    Node *l1 = head1, *l2=head2;
    int len1 = 0, len2 = 0;
    while(l1){
        len1++;
        l1 = l1->next;
    }
    while(l2){
        len2++;
        l2 = l2->next;
    }
    cout<<"\n"<<len2;
    l1 = head1;
    l2 = head2;
    int diff = len1 - len2 ;
    if(diff>0)
        while(diff){
            l1 = l1->next;
            diff--;
        }
    else
        while(diff<0){
            l2 = l2->next;
            diff++;
        }
    while(l1&&l2)
    {
        cout<<endl<<l1->data<<" "<<l2->data;
        if(l1 == l2)
            return l1->data;
        l1 = l1->next;
        l2 = l2->next;
    }
    return -1;
}