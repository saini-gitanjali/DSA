#include<iostream>

using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

node* getNode(int data) {
    node *newNode = new node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(node **head, node *newNode) {
    if(head == NULL) {
        (*head) = newNode;
        (*head)->next = NULL;
    }
    else {
        newNode->next = (*head);
        (*head) = newNode;
    }
}

void print(node *head) {
    node *temp = head;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

node* reverseGroups(node *head, int k) {
    int count = 0;
    node *current = head;
    node* next = NULL;
    node* newHead = NULL;
    while (current != NULL && count < k)
    {
        next = current->next;
        insert(&newHead, current);
        current = next;
        count++;
    }
    if (next != NULL)
    {
        head->next = reverseGroups(next, k);
        head->next->prev = head;
    }
    return newHead;
}

int main() {
    int elt, no_of_nodes, groupSize;
    node *head = NULL;

    cout<<"enter the number of nodes in the linked list : ";
    cin>>no_of_nodes;

    cout<<"enter the group size : ";
    cin>>groupSize;

    cout<<"enter the elements of the linked list :\n";
    for (int i = 0; i < no_of_nodes; i++) {
        cin>>elt;
        insert(&head, getNode(elt));
    }
    cout<<"\nLinked list before reversing\n";
    print(head);
    head = reverseGroups(head ,groupSize);
    cout<<"\nLinked list after reversing\n";
    print(head);

   return 0; 
}