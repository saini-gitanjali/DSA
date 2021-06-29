#include<iostream>
#include<string.h>

using namespace std;

string removeDup(string s) {
    if(s.length() == 0)
        return "";
    char ch = s[0];
    string ans = removeDup(s.substr(1));
    if(ch == ans[0])
        return ans;
    // else
        return (ch+ans);
}


int main() {
    string str;
    cin>>str;
    string ans =  removeDup(str);
    cout<<ans;
    return 0;
}