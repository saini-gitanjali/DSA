// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int x, int y)
    {
        // your code here
        int dp[x+1][y+1], res = 0;
        for(int i=0; i<=x; i++)
            dp[i][0] = 0;
        for(int j=0; j<=y; j++)
            dp[0][j] = 0;
    
        for(int i=1; i<=x; i++)
        {
            for(int j=1; j<=y; j++)
            {
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                    res = max(dp[i][j], res);
                }
                    
                else 
                    dp[i][j] = 0;
                    
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends