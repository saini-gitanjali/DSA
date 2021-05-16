#include<iostream>
#include<string>
using namespace std;

int maxSubString(string str)
{
    int c0 = 0, c1 = 0, count = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '0')
            c0++;
        if(str[i] == '1')
            c1++;
        if(c0 == c1)
            count++;
    }
    return count;
}
int main() {
    string str;
    cin>>str;
    int ans = maxSubString(str);
    if(ans == 0)
        cout<<"there are no substrings of euals 0's and 1's";
    else
        cout<<ans;

    return 0;
}