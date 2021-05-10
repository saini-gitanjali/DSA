// { Driver Code Starts
#include <iostream>
#include<algorithm>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    int low = 0, high = 1, newSum, count  = 0;
	    sort(arr, arr+n);
	    for(int i = 0; i < n-2; i++)
	    {
	        low = i+1;
	        high = n-1;
	        while(low < high )
	        {
	   int x =  arr[i] + arr[high] + arr[low];
	            if( x >= sum){
	                high--;
	            }
	            
	            else{
	                count += high - low;
	                low++;
	            }
	                
	        }
	    }

    return count;	    
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[10000];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends