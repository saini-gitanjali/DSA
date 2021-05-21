#include<iostream>

using namespace std;

struct node{
    int data;
    node *next, *prev;
};

class stack
{
    public:
    node *top ;
    node *mid ;
    int count ;
};

node *newNode(int x) {
    node *n = new node;
    n->data = x;
    n->prev = NULL;
    n->next = NULL;
}
void push(stack *s, int x) {

    node *n = newNode(x);
    if(s->top == NULL) {
        s->top = n;
        s->count++;
        s->mid = s->top;
        cout<<"f";
        return;
    }
    else{
        n->next = s->top;
        (s->top)->prev = n;
        s->top = n;
        s->count++;
        cout<<"k";
    }
     
    if(s->count % 2 != 0)
        s->mid = s->mid->prev; 
       
}

int pop(stack *s) {
    node *t = s->top;
    int x = t->data;
    if(!s->top->next)
    {
        s->top = s->top->next;
        s->count--;
    }
    else{
        s->top = s->top->next;
        s->count--;
    }
    if(s->count == 1){
        s->mid = s->top;
        return x;
    }
    else if(s->count % 2 == 0)
        s->mid = s->mid->next;
    delete(t);
    return x;
}

int getMid(stack *s) {
    return s->mid->data;
}

int deleteMid(stack *s) {
    int x = s->mid->data;
    node *t = s->mid;
    if(s->top->next == NULL)
    {
        s->top = NULL;
        s->count--;
    }
    else
    {
        // t = s->mid;
        s->mid->next->prev  = s->mid->prev;
        s->mid->prev->next = s->mid->next;
        s->count--;
        if(s->count % 2 == 0)
        s->mid = s->mid->prev;
    }
    delete(t);
    return x;
}

void print(stack *t) {
    node * s = t->top;
    if(!t->top)
       std :: cout<<"stack empty";
    while(s)
    {
        std :: cout<<s->data<<" ";
        s = s->next;
    }
}
int main() {
    stack *s = new stack();
    // std :: cout<<"vv";
   
    s->count = 0;
    int choice = 0, ch = 1;
    std :: cout<<"f";
    while(ch == 1){
        ch = 0;
        std :: cout<<"\n1. PUSH";
        std :: cout<<"\n2. POP";
        std :: cout<<"\n3. PRINT STACK";
        std :: cout<<"\n4. GET MIDDLE ELEMENT";
        std :: cout<<"\n5. DELETE MIDDLE ELEMENT";
        std :: cout<<"\nENTER YOUR CHOICE : ";
        std :: cin>>choice;
        switch (choice)
        {
        case 1:
            int n;
            std :: cin>>n;
            push(s, n);
            break;
        case 2: 
            std :: cout<<pop(s);
            break;
        case 3: 
            print(s);
            break;
        case 4:
            cout<<getMid(s); 
            break;
        case 5:
            std :: cout<<deleteMid(s);
            break;
        default:
            break;
        }
        std :: cout<<"\nENTER 1 TO CONTINUE : ";
        std :: cin>>ch;
    }

    
    return 0;


}