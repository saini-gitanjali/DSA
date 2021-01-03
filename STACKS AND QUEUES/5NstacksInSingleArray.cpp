//Create a data structure kStacks that represents k stacks. Implementation of kStacks should use only one array, i.e., k stacks should use the same array for storing elements. Following functions must be supported by kStacks.

//push(int x, int k) –> pushes x to stack number ‘sn’ where sn is from 0 to k-1
//pop(int k) –> pops an element from stack number ‘sn’ where sn is from 0 to k-1
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
    Nstack(int n, int sn);
    void push(int n, int sn);
    int pop(int sn);
    int peek(int sn);
    bool isfull(int sn);
    bool isempty(int sn);

// uncomment this function to see min and max value of top for each stacsn
   /* void utility(int n, int sn){
        for(int i=0; i<sn ; i++)
        cout<<top[i]<<"\t"<<sizeStack[i]<<endl;
    }*/
};

Nstack :: Nstack(int n, int sn)
{
    size = n;
    no_of_stacks =sn;
    stack = new int[n];
    top = new int[sn];
    sizeStack = new int[sn];
    top[0] = -1;
    for(int i=1; i<sn; i++)
        top[i] = top[i-1] + (n/sn);
    for(int i=0; i<sn; i++)
        sizeStack[i] = top[i]+sn-1;
    //stack ={0};
}

bool Nstack :: isfull(int sn){
    if(top[sn-1] == sizeStack[sn-1])
        return true;
    else 
        return false;
}

bool Nstack ::isempty(int sn){
    if(sn == 1)
        if(top[0]==-1)
        {
            // cout<<top[0];
        return true;
        }
    else if(top[sn-1] == sizeStack[sn-2]-1)
        return true;
    else
        return false;
}

void Nstack :: push(int n, int sn){
    if(isfull(sn))
    {
        cout<<"OverFlow";
        return;
    }
    stack[++top[sn-1]] = n;
    //cout<<top[sn-1]<<" "<<stack[top[sn-1]];
}

int Nstack :: peek(int sn){
    
    if(!isempty(sn))
        return stack[top[sn-1]];
        
    else
        cout<<"underflow";
}

int Nstack :: pop(int sn)
{
    if(!isempty(sn))
    {
        int t = stack[top[sn-1]--];
        cout<<top[sn-1]<<endl;
        return t;
    }
    else
        cout<<"underFlow";
}

int main(){
    int n, sn , m;
    cout<<"enter stack size : ";
    cin>>n>>sn;
    
    int choice1=0, choice2=0;
    Nstack st(n, sn);
    //uncomment the below function to see min and max values of taop for each stack
    //st.utility(n, sn);
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