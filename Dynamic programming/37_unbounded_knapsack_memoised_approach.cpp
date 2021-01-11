//problme link:https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
int k[1000][1000];
int knapsack_utility(int n, int w, int val[], int wt[])
{
    if(n==0||w==0)
            return 0;
        if(k[n][w]!=-1)
            return k[n][w];
        else if(wt[n-1]>w)
            return k[n][w] = knapSack(n-1, w, val , wt);
        else
            return k[n][w] = max((val[n-1]+knapSack(n, w-wt[n-1], val, wt)), knapSack(n-1, w, val ,wt));
        
}
    int knapSack(int n, int w, int val[], int wt[])
    {
        
        memset(k, -1, sizeof(k));
        return knapsack_utility(n,w,val,wt);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends