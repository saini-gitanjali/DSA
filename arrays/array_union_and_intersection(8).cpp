#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
void Union(vector<int> v1, vector<int> v2, int n,int m){
    set<int> s;
    for(int i=0;i<n;i++)
        s.insert(v1[i]);
    for(int i=0;i<m;i++)
        s.insert(v2[i]);
    cout<<s.size()<<endl;
}
void intersection(vector<int> v1, vector<int>v2,int n, int m)
{
    set<int> s;
    vector<int>v;
    int count=0;
    for(int i=0;i<n;i++)
        s.insert(v1[i]);
    for(int i=0;i<m;i++)
    {
        if(s.find(v2[i])!=s.end())
            v.push_back(v2[i]);
    }
    cout<<v.size();
}
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, m, k;
	    cin>>n>>m;
	    vector<int> v1, v2;
	    for(int i=0;i<n;i++){
	        cin>>k;
	        v1.push_back(k);
	    }
	      for(int i=0;i<m;i++){
	        cin>>k;
	        v2.push_back(k);
	    }
	    Union(v1, v2, n, m);
	    //cout<<endl;
	    intersection(v1, v2, n,m);
	    //cout<<endl;
	}
	return 0;
}