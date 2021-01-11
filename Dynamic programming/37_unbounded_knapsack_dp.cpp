// { Driver Code Starts
// Initial Template for C++

#include <iostream>
#include<math.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:


    int knapSack(int n, int w, int val[], int wt[])
    {
        int k[n+1][w+1];
        
       if(n==0||w==0)
            return 0;
    for(int i=0; i<=n;i++)
    {
        for(int j=0; j<=w; j++)
        {    
            if((i == 0)||(j == 0))
                k[i][j] = 0;
            else if(wt[i-1]>j)
                 k[i][j] = k[i-1][j];
            else
                k[i][j] = max(val[i-1]+k[i][j-wt[i-1]], k[i-1][j]);
        }   
    }
    return k[n][w]; 
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