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
       stack<long long> s;
    
    for(int i = 0; i < n; i++) {
        if(s.empty())
            nsl.push_back(-1);
        else if(s.size() > 0 && arr[s.top()] < arr[i])
            nsl.push_back(s.top());
        else if(s.size() > 0 && arr[s.top()] >= arr[i]) {
            while(s.size() > 0 && arr[s.top()] >= arr[i])
                s.pop();
            if(s.size() == 0)
                nsl.push_back(-1);
            else
                nsl.push_back(s.top());
        }
        s.push(i);
    }
    while(!s.empty())
        s.pop();
        
        for(int i = n-1; i >= 0; i--) {
        if(s.empty())
            nsr.push_back(n);
        else if(s.size() > 0 && arr[s.top()] < arr[i])
            nsr.push_back(s.top());
        else if(s.size() > 0 && arr[s.top()] >= arr[i]) {
            while(s.size() > 0 && arr[s.top()] >= arr[i])
                s.pop();
            if(s.size() == 0)
                nsr.push_back(n);
            else
                nsr.push_back(s.top());
        }
        s.push(i);
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
  // } Driver Code Ends