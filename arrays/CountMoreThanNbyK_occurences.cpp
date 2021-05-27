// { Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    
    int countOccurence(int arr[], int n, int k) {
        map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++)
            mp[arr[i]]++;
            
        for(auto x : mp)
            if(x.second > n/k)
                ans++;
            
        
        
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends