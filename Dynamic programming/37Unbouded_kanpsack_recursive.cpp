//problem link : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#
// { Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        if(n==0||W==0)
            return 0;
        else if(wt[n-1]>W)
            return knapSack(n-1, W, val , wt);
        else
            return max((val[n-1]+knapSack(n, W-wt[n-1], val, wt)), knapSack(n-1, W, val ,wt));
        
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