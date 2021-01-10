#include<iostream>

using namespace std;
struct node {
    int data;
    node *next;
    node(int n){
        data = n;
        //next = m;
    }
};
class CLL{
    node *head = NULL;
    public :
    void insertHead(int n);
    void insertEnd(int n);
    int deleteHead();
    int deleteEnd();
    int countNodes();
    int isempty();
    void display();
};

int CLL  :: isempty()
{
    if(head==NULL)
        return 1;
    else 
        return 0;
}

void CLL ::insertHead(int n){
    
    if(head == NULL)
    {    head = new node(n);
        head -> next = head;
        return; 
    }

    node *temp = head; 
    while(temp->next != head)
    {
        //cout<<"while";
        temp = temp->next;
    }
    node *newnode = new node(n);
    temp ->next = newnode;
    newnode->next = head;
    head = newnode;
}

void CLL :: insertEnd(int n){
    if(head == NULL)
    {
        head = new node(n);
        head->next= head;
        return;
    }
    node *temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    node *newnode = new node(n);
    temp ->next = newnode;
    newnode->next = head;
    //head = newnode;
    

}

int CLL :: deleteHead()
{
    node *temp = head;
    int n = 0;
    if(temp->next == head)
    {
        n = head->data;
        head = NULL;
        delete head;
    }
    else 
    {
        node *last = head;
        while(last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        n = temp -> data;
        delete temp;
    }
        return n;
}

int CLL :: deleteEnd()
{
    node *temp = head;
    int n = 0;
    if(temp->next == head)
    {
        n = head->data;
        head = NULL;
        delete head;
    }
    else 
    {
        node *prev, *last = head;
        while(last->next != head){
            prev = last;
            last = last->next;
        }
        prev->next = head;
        n = last -> data;
        delete last;
    }
        return n;
    
}

int CLL ::countNodes()
{
    int count = 0;
    if(head == NULL)
        return 0;
    node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    }while(temp != head);
    return count;
}

void CLL :: display()
{
    node *temp = head;
    if(!isempty()){
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while (temp != head);
    }
    else 
        cout<<"\n list empty";
}

int main()
{
    int ch1 = 0, ch2 = 0;
    CLL cll;
    do
    {
        cout<<"\n1. is empty";
        cout<<"\n2. Enter at head";
        cout<<"\n3. insert at end";
        cout<<"\n4. delete from head";
        cout<<"\n5. delete from end";
        cout<<"\n6. total no. of nodes";
        cout<<"\n7. display";
        cout<<"\nenter your choice : ";
        cin>>ch1;
        switch (ch1)
        {

        case 1: if(cll.isempty())
                    cout<<"list empty";
                else 
                    cout<<"List not empty";
                break;
        case 2 : int n;
                cin>>n;
                cll.insertHead(n);
                break;
        case 3 :cin>>n;
                cll.insertEnd(n);
                break;
        case 4 :cout<<cll.deleteHead();
                break;
        case 5 :cout<<cll.deleteEnd();
                break;
        case 6 :cout<<cll.countNodes();
                break;
        case 7 : cll.display();
                break;
        default: cout<<"\nEXITING!!";
            break;
        }
        cout<<"\nenter 1 to continue : ";
        cin>>ch2;
    } while (ch2 == 1);
    
}