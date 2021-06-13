// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int lis[n+1],  ans=0;
        
        for(int i=1; i<=n; i++)
            lis[i] = INT_MAX;
        lis[0] = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            int j = upper_bound(lis, lis+n+1, a[i])-lis;
            if( a[i] > lis[j-1] && a[i]<lis[j]){
                
                lis[j] = a[i];
            } 
        }
        for(int i=0; i<=n; i++){
            if(lis[i] != INT_MAX)
                ans = i;
        }
            return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends