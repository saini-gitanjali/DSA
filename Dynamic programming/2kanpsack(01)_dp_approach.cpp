problme link:
//using dp top down approach
#include<iostream>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) 
{ 
    int k[n+1][W+1];
    int v, w;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(i==0||j==0)
                k[i][j]=0;
            if(wt[i-1]<j){
                k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]], k[i-1][j]);
            }
            else
            k[i][j] = k[i-1][j];
            
        }
    }
    return k[n][w];
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
        
        int val[n];
        int wt[n];
        
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