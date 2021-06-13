// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    int LCSlen(string &str1, string &str2, int n, int m)
	{
	    int dp[n+1][m+1];
	    for(int i=0; i<=n; i++)
	        for(int j=0; j<=m; j++)
	            if(i==0||j==0)
	               dp[i][j] = 0;
	            else if(str1[i-1] == str2[j-1])
	                dp[i][j] = dp[i-1][j-1]+1;
	           else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	   return dp[n][m];
	    
	}
    int minimumNumberOfDeletions(string s) { 
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s.length() - LCSlen(s, rev, s.length(), rev.length());
    } 
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
return 0;
}  // } Driver Code Ends