//using memoization in recursive approach
#include<iostream>
using namespace std;

int k[1000][1000];

int knapSack_utility(int W, int wt[], int val[], int n) 
{ 
    if(n==0||W==0)
        return 0;
    if(k[n][W]!=-1)
        return k[n][W];
    if(wt[n-1]<=W)
        return k[n][W] = max(val[n-1]+knapSack_utility(W-wt[n-1], wt, val, n-1), knapSack_utility(W, wt, val ,n-1));
    else if(wt[n-1]>W)
        return k[n][W] = knapSack_utility(W, wt, val, n-1);
}
int knapSack(int W, int wt[], int val[], int n)
{
    memset(k, -1, sizeof(k));
    return knapSack_utility(W,wt,val, n);
    
}


int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int *val =  new int[n];
        int *wt =  new int[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends