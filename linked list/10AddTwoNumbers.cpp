// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


Node *revList(Node *head){
    Node *curr=head, *prev=NULL, *next;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node * addUtil(Node *head1, Node *head2){
    Node  *temp;
    int a, b,  sum = 0, carry  = 0;
    Node *res = new Node(0);
    temp = res;
    while (head1||head2)
    {
        sum =  carry +(head1 ?  head1->data:0)+(head2? head2->data :0);
        carry =  sum/10;
            temp->next = new Node(sum%10);
        
        temp = temp->next;
        if(head1!=NULL)
        head1 = head1->next;
        if(head2!=NULL)
        head2 = head2->next;
    }
    if(carry>0)
    temp->next = new Node(carry);
    return res->next;
    
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node *temp1 = revList(first);
    Node *temp2 = revList(second);
    Node *temp3 = addUtil(temp1, temp2);
    return revList(temp3);
}