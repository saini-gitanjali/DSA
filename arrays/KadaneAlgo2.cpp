// { Driver Code Starts
#include<iostream>
#include<vector>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int maxSubarraySum(int arr[], int n){
        int s, start, end, sum , maxSum = -1000000;
        s = 0;
        start = 0;
        end =  0;
        sum = 0;
      for(int i = 0; i < n; i++)
      {
          sum += arr[i];
          if(maxSum < sum)
          {
              maxSum = sum;
              start = s;
              end = i;
          }
          else if(sum < 0)
          {
              sum = 0;
              s++;
          }
          cout<<endl;
          cout<<"\ni = "<<i;
          cout<<"\nmaxSum = "<<maxSum;
          cout<<"\nsum = "<<sum;
          cout<<"\ns = "<<s;
          cout<<"\n start = "<<start;
          cout<<"\n end = "<<end;
          
      }
      
    cout<<endl;
    return maxSum; 
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int *a = new int[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends