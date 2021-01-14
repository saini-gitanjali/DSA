// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
  public:
    long long int count( int S[], int m, int N )
    {
        long long int dp[m+1][N+1];
        memset(dp, 0, sizeof(dp));
        for(int i =0; i<= m; i++)
        {
            
            for(int j=0; j <= N ; j++)
            {
                if(i==0) dp[i][j] = 0;
                if(j==0) dp[i][j] = 1;
              //  cout<<dp[i][j]<<" ";
                
            }
           // cout<<endl;
        }
        for(int i =1; i<= m; i++)
        {
            
            for(int j=1; j <= N ; j++)
            {
            
            
            if(S[i-1]<=j)
                dp[i][j] = dp[i-1][j]+dp[i][j-S[i-1]];
            else
                dp[i][j] = dp[i-1][j];
                //cout<<dp[i][j]<<" ";
            }
           // cout<<endl;
        }
        
        /*if (m <=0 && n >= 1) 
        return 0;
        return count(S,m-1,n)+count(S,m,n-S[m-1]);
        */
        return dp[m][N];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends