//Check if a string is a valid shuffle of two other strings
// str1 = xy , str2 = 12, result = x12y gives output true
// result = y12x gives out false as the order of characters of str1 is reverses , y appears before x
#include<iostream>
#include<string>

using namespace std;
bool isValidShuffle(string str1, string str2, string result){
    if(str1.length()+str2.length() != result.length())
        return false;
    int k = 0, i = 0, j = 0;
    while(k < result.length()){
        if(str1[i] == result[k])
            i++;
        else if(str2[j] == result[k])
            j++;
        else 
            return false;
        k++;
    }
    return true;
}

int main(){
    string s1, s2, result;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, result);
    if(isValidShuffle(s1, s2, result))
        cout<<"true";
    else    
        cout<<"false";
    return 0;
}