#include <iostream> 
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
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

Node* addOne(Node *head);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        
        head = addOne(head);
        printList(head); 
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

Node *add(Node *head_ref){
    Node *temp = NULL;
    Node *res = head_ref;
    int sum=0, carry = 1;
    while(head_ref!=NULL)
    {        
        sum = head_ref->data + carry;
        carry = sum>=10? 1:0;
        if(carry == 0)
            head_ref->data = sum;
        else
        {
            head_ref->data = sum%10;
        }
        temp = head_ref;
        //cout<<temp->data<<" ";
        head_ref = head_ref->next;
        
    }
    if(carry>0)
    temp->next = new Node(carry);
    //cout<<endl;
    return res;
}

Node* addOne(Node *head) 
{
    Node *temp;
    temp = revList(head);
    Node *temp1 =  add(temp);
    return revList(temp);        
}