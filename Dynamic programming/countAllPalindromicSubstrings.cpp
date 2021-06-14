// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    long long int dp[1000][1000];
    long long int mod = 1000000007;
    long long int countP(string &str,int i, int j)
{

    if (i > j)  
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    
    if (i == j)
        return dp[i][j] = 1;
    
    else if (str[i] == str[j])
        return dp[i][j]
        = (countP(str,i + 1, j)%mod +
        countP(str,i, j - 1)%mod + 1 + mod)%mod;
    
    else
        return dp[i][j] = (countP(str,i + 1, j)%mod + countP(str,i, j - 1)%mod - countP(str,i + 1, j - 1)%mod  + mod)%mod;
}
    long long int  countPS(string str)
    {
        long long int n = str.length()-1;
        memset(dp , -1, sizeof(dp));
        return countP(str, 0, n);
    }
     
};

// { Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}  // } Driver Code Ends