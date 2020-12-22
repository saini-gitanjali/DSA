#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
void findDup(string s){
    int count =0;
    unordered_map <char, int> map;
    for(int i=0;i<s.length(); i++){
        map[s[i]]++;
    }
    cout<<"character"<<"\t"<<"count"<<endl;
    for(auto itr = map.begin(); itr != map.end(); itr++)
        if(itr->second>1){
            cout<<itr->first<<"\t"<<itr->second<<endl;
            count++;
        }
        if(count==0)
        cout<<"NO duplicac found";
        else
        {
            cout<<endl<<count<<"  duplicate characters were found";
        }
        
}
int main(){
    string str;
    cin>>str;
    findDup(str);
    return 0;
}