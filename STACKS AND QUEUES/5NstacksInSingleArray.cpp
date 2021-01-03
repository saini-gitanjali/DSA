#include<iostream>
#include<stdio.h.>
#include<string.h>

using namespace std;

class Nstack{
    int size;
    int *stack;
    int *top;
    int *sizeStack;
    int no_of_stacks;

    public:
    Nstack(int n, int k);
    void push(int n, int k);
    int pop(int k);
    int peek(int k);
    bool isfull(int k);
    bool isempty(int k);

// uncomment this function to see min and max value of top for each stack
   /* void utility(int n, int k){
        for(int i=0; i<k ; i++)
        cout<<top[i]<<"\t"<<sizeStack[i]<<endl;
    }*/
};

Nstack :: Nstack(int n, int k)
{
    size = n;
    no_of_stacks = k;
    stack = new int[n];
    top = new int[k];
    sizeStack = new int[k];
    top[0] = -1;
    for(int i=1; i<k; i++)
        top[i] = top[i-1] + (n/k);
    for(int i=0; i<k; i++)
        sizeStack[i] = top[i]+k-1;
    //stack ={0};
}

bool Nstack :: isfull(int k){
    if(top[k-1] == sizeStack[k-1])
        return true;
    else 
        return false;
}

bool Nstack ::isempty(int k){
    if(k == 1)
        if(top[0]==-1)
        {
            // cout<<top[0];
        return true;
        }
    else if(top[k-1] == sizeStack[k-2]-1)
        return true;
    else
        return false;
}

void Nstack :: push(int n, int k){
    if(isfull(k))
    {
        cout<<"OverFlow";
        return;
    }
    stack[++top[k-1]] = n;
    cout<<top[k-1]<<" "<<stack[top[k-1]];
}

int Nstack :: peek(int k){
    
    if(!isempty(k))
        return stack[top[k-1]];
        
    else
        cout<<"underflow";
}

int Nstack :: pop(int k)
{
    if(!isempty(k))
    {
        int t = stack[top[k-1]--];
        cout<<top[k-1]<<endl;
        return t;
    }
    else
        cout<<"underFlow";
}

int main(){
    int n, k , m;
    cout<<"enter stack size : ";
    cin>>n>>k;
    
    int choice1=0, choice2=0;
    Nstack st(n, k);
    //uncomment the below function to see min and max values of taop for each stack
    //st.utility(n, k);
    do {
            cout<<"\n1.push";
            cout<<"\n2.pop";
            cout<<"\n3.isempty";
            cout<<"\n4.display top";
            cout<<"\n5.isFull";
            cout<<"\n enter you choice : ";
            cin>>choice1;
            switch(choice1){
                    case 1: int x;
                            cin>>x>>m;
                            st.push(x, m);
                            break;
                    case 2: cin>>m;
                            
                                x = st.pop(m);
                            if(!st.isempty(m))
                            {
                                cout<<x;
                            }
							break;
                    case 3: cin>>m;
                            if(st.isempty(m))
                                cout<<"\n stack empty";
                            else 
                                cout<<"\n stack not empty";
                            break;
                    case 4: cin>>m;
                            cout<<"\n"<<st.peek(m);
                            break;
                    case 5: cin>>m;
                            if(st.isfull(m))
                                cout<<"stack full";
                            else
                            {
                                cout<<"stack not full";
                            }
                            break;
                    default: cout<<"\nexiting";
                                exit(0);
            }
            cout<<"\nenter 1 to continue : ";
            cin>>choice2;
    }while(choice2==1);
}