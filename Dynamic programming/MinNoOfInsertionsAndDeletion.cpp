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
	int minOperations(string str1, string str2)  
	{ 
	    int len = LCSlen(str1, str2, str1.length(), str2.length());
	    return (str1.length()-len) + (str2.length()-len);
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends