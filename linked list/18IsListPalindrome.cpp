//problem link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
bool isPalindrome(Node *head)
{
    stack<int> st;
    Node *slow, *fast;
    slow = fast = head;
    while(fast->next && fast->next->next!=NULL)
    {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next){
        if(fast->next->next == NULL)
        {
            st.push(slow->data);
            slow = slow->next;
        }
    }
    else 
        slow = slow->next;
    while(slow)
    {  
        int a = st.top();
        st.pop();
        if(a != slow->data)
            return false;
        slow = slow->next;
    }
    return true;
}