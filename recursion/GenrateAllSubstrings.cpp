#include<iostream>
#include<string.h>

using namespace std;

void subSeq(string str, string ans)
{
    if(str.length()==0){
        cout<<ans<<endl;
        return ;
    }
    char ch = str[0];
    string ros = str.substr(1);
    subSeq(ros, ans);
    subSeq(ros, ans+ch);
}
int main()
{
    string str;
    cin>>str;
    subSeq(str, "");
    return 0;
}
