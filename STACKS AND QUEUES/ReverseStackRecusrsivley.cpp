#include<iostream>
#include<stack>

using namespace std;

void insert(stack<int> &s, int item) {
    if(s.empty()) {
        s.push(item);
        return;
    }
    int top = s.top();
    s.pop();
    insert(s, item);
    s.push(top);
}

void reverse(stack<int> &s) {
    if(s.empty())
        return;
    
    int n = s.top();
    s.pop();
    reverse(s);
    insert(s, n);

}

int main() {
    int n = 5, x;
    stack<int> s;
    cin>>n;
    while(n--) {
        cin>>x;
        s.push(x);
    }
    
    reverse(s); 
    cout<<"Reversed stack is : "<<endl;
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }   
    return  0;
}