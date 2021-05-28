// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	   long long int minval  = arr[0];
	   long long int maxval = arr[0];
	   long long int result = arr[0];
	   
	   for(int i = 1; i < n; i++)
	   {
	       long long x = arr[i];
	       
	       if(x < 0)
	            swap(minval , maxval);
	        
	       maxval = max(x, maxval*x);
	       minval = min(x ,  x*minval);
	           // minval = x*minval;
	       
	   
	       
	       result= max(result, maxval);
	   }
	   return result;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends