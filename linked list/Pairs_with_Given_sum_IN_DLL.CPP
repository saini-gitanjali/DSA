#include<iostream>
 using namespace std;
 struct Node
 {
     int data;
     Node *next;
     Node *prev;
     
 };
 void printSum(Node *curr, int sum)  {
    struct Node *first = curr, *second= curr;
    while(second->next)
        second = second->next;
    while(first != NULL && second != NULL &&
        first != second && second->next != first)
    {
        
        if(first->data + second->data == sum)
        {
            cout<<first->data<<" "<<second->data<<endl;
            first = first->next;
            second = second->prev;
        }
        else if(first->data +  second->data < sum)
            first =  first->next;
        else
            second = second->prev;
    }
 }
 void insert(Node **head,int a){                         //insert at head
        Node *node = new Node;
        node->data = a;
        node ->prev = NULL;
        node->next = NULL;
     if(!(*head)){
        *head =  node;
        
     }
     else{
        
        node->next = (*head);
        (*head)->prev = node;
       // node ->prev = NULL; 
        (*head) = node;
     } 
 }
 void print(Node *temp_head)
 {
     while(temp_head){
        cout<<temp_head->data<<" ";
        temp_head = temp_head->next;
     }
 }
 int main(){
     Node *head = NULL;
     int n, elt, sum;
     cin>>n;
     while(n--)
     {
         cin>>elt;
         insert(&head, elt);
     }
     cin>>sum;
     printSum(head, sum);
    //  print(head);
     return 0;
 }