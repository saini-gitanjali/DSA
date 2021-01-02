//Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
//(eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)

#include<iostream>
#include<string>
using namespace std;

bool isRotatation(string str1, string str2){
        
        string str3 = str1+str1;
    if(str3.find(str2)!=string::npos)
        return true;
    else
    {
        return false;
    }

}
int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int len1 = str1.length();
    int len2 = str2.length();
    if(len1!=len2)
        return false;
    if(str1==str2)
    {   
        cout<<"false";
    }
    else if(isRotatation(str1, str2))
        cout<<"True";
    else
    {
        cout<<"False";
    }
    return 0;
}