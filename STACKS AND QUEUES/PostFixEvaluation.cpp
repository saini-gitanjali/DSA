// { Driver Code Starts
// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int> result;
        for(int i = 0; i < s.length(); i++)
        {
            // cout<<result.top()<<endl;
            if(s[i] >= '0' && s[i] <= '9')
                result.push(s[i] - '0');
            else 
            {
                int b = result.top();
                result.pop();
                int a = result.top();
                result.pop();
                switch(s[i]) {
                    case '+' : result.push(a + b);
                        break;
                    case '-' : result.push(a- b);
                        break;
                    case '*' : result.push(a * b);
                        break;
                    case '/' : result.push(a / b);
                        break;
                   
                }
            }
            
        }
        return result.top();
        // return 0;
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends