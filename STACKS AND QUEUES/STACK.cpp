#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class stack{
    private:
        int size;
        int *st;
        int top;
public:
    stack(int n);
    int peek();
    bool isempty();
    int pop();
    void push(int n);
};

stack :: stack(int n){
        size = n;
        st = new int[n];
        top = -1;        
}

void stack :: push(int n){
    if(top == size-1){
        cout<<"overflow";
    }
    top++;
    st[top] = n;
    //cout<<st[top]<<" pushed";
}


int stack :: pop(){
    if(top == -1)
        return -1;
    int x = st[top];
    top--;
    return x;
	    
}


int stack:: peek(){
    
    if(top == -1)
        return -1;
    int n = st[top];
        return n;
}

bool stack :: isempty(){
    if(top == -1)
        return true;
    else 
    return false; 
}

int main(){
    int n;
    cout<<"enter stack size : ";
    cin>>n;
    int choice1=0, choice2=0;
    stack st(n);
    do {
            cout<<"\n1.push";
            cout<<"\n2.pop";
            cout<<"\n3.isempty";
            cout<<"\n4.display top";
            cout<<"\n enter you choice : ";
            cin>>choice1;
            switch(choice1){
                    case 1: int x;
                    		cin>>x;
                            st.push(x);
                            break;
                    case 2: x = st.pop();
                            cout<<x;
							break;
                   case 3: if(st.isempty())
                                cout<<"\n stack empty";
                            else 
                                cout<<"\n stack not empty";
                            break;
                    case 4: cout<<"\n"<<st.peek();
                            break;
                    default: cout<<"\nexiting";
                                exit(0);
            }
            cout<<"\nenter 1 to continue : ";
            cin>>choice2;
    }while(choice2==1);
}
