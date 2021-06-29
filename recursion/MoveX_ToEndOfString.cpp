#include<iostream>
#include<string.h>

using namespace std;

string move(string s){
    if(s.length()==0)
        return "";
    char ch = s[0];
    string ros = move(s.substr(1));
    if(ch=='x'){
        
        return ros+ch;
        }
    return ch+ros;

}
int main()
{
    string s;
    cin>>s;
    cout<<move(s);
    return 0;

}