/*Rotate Doubly linked list by N nodes
Difficulty Level : Easy
Last Updated : 17 Sep, 2019
Given a doubly linked list, rotate the linked list counter-clockwise by N nodes*/
//https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/
#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};


void insert(node **head, int elt)
{
    node *newNode =  new node;
    newNode->data = elt;
    newNode->next = NULL;
    newNode->prev = NULL;
    if((*head) == NULL)
        (*head) = newNode;   
    else 
        newNode->next = (*head);
    *head = newNode;  
}

// node findLast(node *head)
// {
//     node *temp = head;
//     while(temp->next != NULL)
//         temp = temp->next;
//     return *temp;
// }

void rotate(node **head, int k)
{
    node *last, *temp;
    last = *head;
    while(last->next != NULL)
        last = last->next;
    for (int i = 0; i < k; i++)
    {
        temp = (*head);
        *head = (*head)->next;
        last->next = temp;
        temp->prev = last;
        temp->next = NULL;
        (*head)->prev = NULL;
        last = temp;

    }
    
    
}

void print(node *head)
{
    node *temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } 
}
int main()
{
    struct node *head = NULL; 
    int n, k , elt;
    cout<<"enter number of nodes in the linked list : ";
    cin>>n;
    cout<<"enter by how many nodes you want to rotate the list : ";
    cin>>k;
    cout<<"enter linked list elements: \n";
    for(int i = 0; i<n; i++)
    {
        cin>>elt;
          insert(&head, elt);
    }
    cout<<"\nlist before rotating : \n";
    print(head);
    // rotate(head, n, k);
    cout<<"\nlist after rotating : \n";
    rotate(&head, k);
    print(head);
    return 0;
}