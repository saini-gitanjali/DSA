// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> cost;
        int  sum = 0, n=N;
        sort(candies, candies+N);
        
        for(int i = 0; i < n; i++){
            sum += candies[i];
            n = n-K;
        }
        cost.push_back(sum);
        
        sum = 0;
        int c=0;
        
        for(int i = N-1; i >= c; i--) {
            sum += candies[i];
            c += K;
        }
            
        cost.push_back(sum);
        return cost;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends