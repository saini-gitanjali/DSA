// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends





/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* mergeSort(Node* head) {
    mergeSORT(&head);
    return head;
}
Node** mergeSORT(Node **head) {
    Node *current = *head;
    Node *slow, *fast, *first, *second;
    slow = current;
    fast = current;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    first = current;
    second = slow->next;
    slow->next = NULL;
    first = mergeSORT(&second);
    merge(&first, &second);
}
Node *merge(Node *l1, Node *l2)
{
    Node *result;
    if(l1 == NULL)
        return result = l1;
    else if(l2 == NULL)
        return l2;
    while(l1||l2)
    {
        if(l1->data,l2->data)
            {
                result = l1;
                result->next = merge(l1->next, l2);
            }
            else
            {
                result = l2;
                result->next = merge(l1, l2->next);
            }
    }
    if(l1)
        result -> next = l1;
    if(l2)
        result->next = l2;
    return result;
}



// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends