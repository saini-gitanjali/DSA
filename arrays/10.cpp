
#include<iostream>
using namespace std;


 // } Driver Code Ends



// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){

 /*   int maxReach=arr[0];
    int steps=arr[0];
    int jump=1;
    for(int i=1;i<n;i++){
        cout<<i<<"\t"<<maxReach<<"\t"<<jump<<"\t"<<steps;
        cout<<endl;
        if(i==n-1)
            return jump;
        maxReach=max(maxReach,i+arr[i] );
        steps--;
        if(steps==0)
            jump++;
        steps=maxReach-i;
        if(i>=maxReach)
            return -1;
            
    }
    return -1;
*/
    int *jumps = new int[n];
    int i, j;
    jumps[0]=0;

    for(i=0;i<j;i++){
        jumps[i]=INT_MAX;
        for(j=1;j<i;j++){
            if(i<=j+arr[j]){
                jumps[i]=min(jumps[i], jumps[j]+1);
            }

        }
    }
    return jumps[n-1];
}


// { Driver Code Starts.

int main()
{
   int t;
   cin>>t;
   for(int i=0;i<t;i++)
   {
       int n;
       cin>>n;
       int *arr= new int;
       for(int i=0;i<n;i++)
       cin>>arr[i];
     int ans = minJumps(arr, n);
     cout<<ans;
     cout<<endl;
   }
  
    return 0;
}