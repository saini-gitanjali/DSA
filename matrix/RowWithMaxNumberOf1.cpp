// { Driver Code Starts
#include <iostream>
#include<vector>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int i =0 , j = m-1;
	    int result = -1;
	   // int m = arr.size(), j = arr[0].size();
	    while(i < n&& j >= 0) {
	        if(arr[i][j] == 1) {
	            result = i;
	            j--;
	        }
	        else 
	         i++;
	        
	    }
	   return result;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends