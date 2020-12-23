//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

#include <iostream>
using namespace std;
   bool isSubset(int n, int arr[], int sum)
    {
        //cout<<"solving";
        int t[1000][1000];
        for (int i = 0; i <= n; i++)
        t[i][0] = true;
    for (int i = 1; i <= sum; i++)
        t[0][i] = false;
        
        for(int i=1; i<n+1; i++)
            for(int j=1; j<sum+1; j++)
            {
                if(arr[i-1]<=j)
                    t[i][j] = t[i-1][j-arr[i-1]]||t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        return  t[n][sum];
    }

int main(){
    int t;
    cin>>t;
    while(t){
        int N, sum;
        cin>>N;
        int *arr =  new int[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        cin>>sum;
       // Solution ob;
        if(isSubset(N, arr, sum))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    t--;
    }
    return 0;
}  