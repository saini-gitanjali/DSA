// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void permutation(string s, vector<string> &res, string ans)
	{
	    if(s.length()==0)
	    {
	        res.push_back(ans);
	        return;
	    }
	    
	    for(int i=0;i<s.length(); i++){
	        char ch = s[i];
	        string s1 = s.substr(0, i)+s.substr(i+1);
	        permutation(s1, res, ans+ch);
	        
	    }
	}
		vector<string>find_permutation(string S)
		{
		   vector<string> res;
		   string ans ="";
		   permutation(S, res, ans);
		   sort(res.begin(), res.end());
		   return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends