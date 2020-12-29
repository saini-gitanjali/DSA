#include <iostream>
using namespace std;

struct Node {
int data;
  struct Node *next;
Node(int x) {
    data = x;
    next = NULL;
}
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T=1;
	//cin>>T;

	while(T--)
	{
		int K=5;
		//cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}

Node*  merge(Node *l1, Node *l2)       //using merge sort to sort the list
{
    if(!11)
        return l2;
    if(!l2)
    return l1;
    
    if(l1->data<l2->data){
        l1->next=merge(l1->next, l2);
        return l1;
    }
    if(l2->data<l1->data){
        l2->next = merge(l1, l2->next);
        return l2;
    }
}
Node *split(Node *head)
{
    if(head==NULL)
        return head;
   
    Node *slow=head, *fast=head;
    while (fast&&fast->next)
    {
        slow=slow->next;
        fast = fast->next->next;
    }
    Node * split_point = slow;
    return merge(split(split_point), split(split_point));
    
}
Node *removeDuplicates(Node *root)
{
 // your code goes here
 Node* temp=split(root);
 Node* l;
 if(temp==NULL)
    return root;
 while(temp->next!=NULL)
{
    if(temp->data==temp->next->data)
    {
        l=temp->next->next;
        free(temp->next);
        temp->next=l;
    }
    else
        temp=temp->next;
}
    
    return root;
 
}