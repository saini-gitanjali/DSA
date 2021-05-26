// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:

    long long getMaxArea(long long arr[], int n)
    {
        // long long area[n];
        
        vector<long long> nsl;
        vector<long long> nsr;
        long long maxArea = INT_MIN;
       stack<pair<long long, int>> s;
    
    for(int i = 0; i < n; i++) {
        if(s.empty())
            nsl.push_back(-1);
        else if(s.size() > 0 && s.top().first < arr[i])
            nsl.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first >= arr[i]) {
            while(s.size() > 0 && s.top().first >= arr[i])
                s.pop();
            if(s.size() == 0)
                nsl.push_back(-1);
            else
                nsl.push_back(s.top().second);
        }
        s.push(make_pair(arr[i], i));
    }
    while(!s.empty())
        s.pop();
        
        for(int i = n-1; i >= 0; i--) {
        if(s.empty())
            nsr.push_back(n);
        else if(s.size() > 0 && s.top().first < arr[i])
            nsr.push_back(s.top().second);
        else if(s.size() > 0 && s.top().first >= arr[i]) {
            while(s.size() > 0 && s.top().first >= arr[i])
                s.pop();
            if(s.size() == 0)
                nsr.push_back(n);
            else
                nsr.push_back(s.top().second);
        }
        s.push(make_pair(arr[i], i));
    }
    reverse(nsr.begin(), nsr.end());
        for(int i = 0; i < n; i++){
            nsl[i] = (nsr[i] - nsl[i] - 1)*arr[i];
           
        }
        return *max_element(nsl.begin(), nsl.end());
        
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
 