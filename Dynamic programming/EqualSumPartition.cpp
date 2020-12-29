///*Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements 
//in both parts is the same.
//problem link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

#include <iostream>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
   bool subsetSum(int n, int arr[], int sum)
    {
        bool t[n+1][sum+1];
       // memset(t, 0, sizeof(t));
        
        for (int i = 0; i <= n; i++)
        t[i][0] = true;
         for (int i = 1; i <= sum; i++)
        t[0][i] = false;
        
        for(int i=1; i<=n; i++)
            for(int j=1; j<=sum; j++)
            {
                if(arr[i-1]<=j)
                    t[i][j] = t[i-1][j-arr[i-1]]||t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
            //cout<<t[n][sum];
        return  t[n][sum];
    }
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        int target = sum/2;
        if(sum%2!=0)
            return false;
        
        else if(sum%2==0)
             return subsetSum(n, arr, target);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends