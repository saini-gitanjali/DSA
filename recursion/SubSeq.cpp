#include<iostream>
#include<string.h>
#include<string>

using namespace std;

void subseq(string str, string ans)
{
    if(str.length()==0){
        cout<<ans<<endl;
        return ;
    }
    char ch = str[0];
    int code = ch;
    string ros = str.substr(1);
    subseq(ros, ans);
    subseq(ros, ans+ch);
    subseq(ros, ans + to_string(ch));
}

int main() {
    string str;
    cin>>str;
    subseq(str, "");
    return 0;
}