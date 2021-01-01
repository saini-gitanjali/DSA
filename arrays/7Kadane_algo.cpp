// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
#include<iostream>
using namespace std;

int maxSubarraySum(int arr[], int n){
int curr_sun=arr[0];
int max_sum=arr[0];
for(int i=1;i<n;i++)
{
    curr_sun=max(arr[i], curr_sun+arr[i]);
    max_sum=max(curr_sun, max_sum);
}
  return max_sum;
  }
int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int *a=new int[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}