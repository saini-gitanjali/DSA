// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int findlcs(char *s1, char *s2, int m, int n)
    {
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++)
            for(int j=0; j<=n; j++)
            {
                if(i==0||j==0)
                    dp[i][j] = 0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            return dp[m][n];
            
    }
    int shortestCommonSupersequence(char* X, char* Y, int m, int n)
    {
        int l1 = strlen(X);
        int l2 = strlen(Y);
        
        int lcs  = findlcs(X, Y, m, n);
        
        int ans = l1+l2-lcs;
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

  // } Driver Code Ends