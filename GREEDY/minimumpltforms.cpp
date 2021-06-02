// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	int platform[n+n], temp = 0, size = n+n, max = 0;
    	platform[0] = 0;
    	vector<pair<int, char>> v;
    	
    	for(int i=0; i<n; i++)
    	{
    	    v.push_back({arr[i], 'a'});
    	    
    	}
    	for(int i=0; i<n; i++)
    	{
    	    v.push_back({dep[i], 'd'});
    	    
    	}
    	sort(v.begin(), v.end());
    	
    
    	for(int i=0; i<size; i++)
    	{
    	    if(v[i].second == 'a')
    	        platform[i] = temp+1;
    	    else
    	        platform[i] = temp-1;
    	   temp = platform[i];
    	   temp = platform[i];
    	   if(max<platform[i])
    	    max = platform[i];
    
    	}
    	
    	return max;
    	
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends