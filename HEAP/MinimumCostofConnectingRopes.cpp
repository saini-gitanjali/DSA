// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    
    long long minCost(long long arr[], long long n) {
        long long int minCost = 0;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq(arr, arr + n);
        
        while(pq.size()>1) {
            long long int a = pq.top();
            pq.pop();
            long long int  b = pq.top();
            pq.pop();
            
            long long int sum = a+b;
            minCost += sum;
            pq.push(sum);
        }
        return minCost;
        
    }
};


// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }  
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends