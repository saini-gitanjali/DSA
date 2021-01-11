//problme link: https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        
        //calling function maximizeTheCuts()
        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}// } Driver Code Ends


//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n+1];
    //dp[0] = 0;
   // memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i=1; i<=n; i++)
    { 
        dp[i] = -1;
        if(i-x >= 0)
            dp[i] = max(dp[i], dp[i-x]);
        if(i - y >= 0)
            dp[i] = max(dp[i], dp[i-y]);
        if(i - z >= 0)
            dp[i] = max(dp[i], dp[i-z]);
        if(dp[i] != -1)
            dp[i]++;
    }
    return max(dp[n], 0);
}