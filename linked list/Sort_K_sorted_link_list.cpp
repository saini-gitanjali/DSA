/*https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/
Sort a k sorted doubly linked list
Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list. 
*/

#include<iostream>
#include<queue>

using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct compare {
	bool operator()(struct Node* p1, struct Node* p2)
	{
		return p1->data > p2->data;
	}
};

struct Node* sortAKSortedDLL(struct Node* head, int k, int n)
{
	Node *temp = head, *temp2 = NULL, *newNode = NULL, *last;
	priority_queue<Node*, vector<Node*>, compare> pq;
	for (int i = 0; i < n; i++)
	{
		pq.push(temp);
		temp = temp->next;	
	}
	while(!pq.empty())
	{
		 if(newNode == NULL){
			 newNode = pq.top();
			 newNode->prev = NULL;
			 last  = newNode; 
		 }
		 else
		 {
			 last->next = pq.top();
			 pq.top()->prev = last;
		     last = pq.top();	 
		 }
		pq.pop();
	}
	last->next = NULL;
	return newNode;
}

// Function to insert a node at the beginning of the Doubly Linked List
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}

void printList(struct Node* head)
{\
	if (head == NULL)
		cout << "Doubly Linked list empty";
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main()
{
    int n, k, i, elt;
	struct Node* head = NULL;
    cout<<"enter the number of elements of linked list: ";
    cin>>n;
    cout<<"Enter the elements of linked list\n";
    for ( i = 0; i < n; i++)
    {
        cin>>elt;
		push(&head, elt);
    }
    cin>>k;
	cout << "Original Doubly linked list:\n";
	printList(head);
	head = sortAKSortedDLL(head, k, n);
	cout << "\nDoubly linked list after sorting:\n";
	printList(head);
	return 0;
}
