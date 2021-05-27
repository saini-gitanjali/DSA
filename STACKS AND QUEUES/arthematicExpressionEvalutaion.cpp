#include<iostream>
#include<vector>
#include<stack>

using namespace std;



int precedence(char op) {
    cout<<"1";
    if(op == '^')
        return 1;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 3;
}

int calculate(int a, int b, char op)
{
    cout<<"2";
    switch (op)
    {
    case '^': return (a^b);
        break;
    case '+': return a+b;
        break;
    case '-': return a-b;
        break;
    case '*': return a*b;
        break;
    case '/': return a/b;
        break;
    }
}

int evaluate(vector<char> &exp, int n) {

    stack<int> values;
    stack<char> ops;    
    for(int i = 0 ; i < n; i++)
    {
        
        if(exp[i] == ' ')
            continue;
        else if(isdigit(exp[i])){
            cout<<"a";
            values.push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                cout<<"b";
                int b  = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                calculate(a, b, op);
            }

            if(!ops.empty()){
                ops.pop();
                cout<<"c";
                }
        
        // print(ops, values);
        }
        else 
        {
                while(!ops.empty() && precedence(ops.top()) >= precedence(exp[i]))
                { 
                    int val2 = values.top(); 
                    values.pop(); 
                    
                    int val1 = values.top(); 
                    values.pop(); 
                    
                    char op = ops.top(); 
                    ops.pop(); 
                    
                    values.push(calculate(val1, val2, op)); 
                    cout<<"d";
                
                }
                ops.push(exp[i]);
        }
        cout<<i<<" ";
        cout<<"values.top() "<<values.top()<<" ";
        cout<<"ops.top() "<<ops.top()<<endl;
    }
      while(!ops.empty()){ 
          cout<<"e";
        int val2 = values.top(); 
        values.pop(); 
                  
        int val1 = values.top(); 
        values.pop(); 
                  
        char op = ops.top(); 
        ops.pop(); 
                  
        values.push(calculate(val1, val2, op)); 
    } 
      
    // return values.top();   
     
    // Top of 'values' contains result, return it.
    return values.top();
}

int main() {
    vector<char> exp;
    int n;
    cin>>n;
    // cout<<n;
    for(int i = 0; i < n; i++){
        char p;
        cin>>p;
        exp.push_back(p);
    }
    cout<<evaluate(exp, n);
    return 0;
}