// { Driver Code Starts
// Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size(), swaps = 0;
	    vector<pair<int, int>> v;
	    for(int i = 0; i < n; i++)
	        v.push_back(make_pair(nums[i], i));
	       
	    sort(v.begin(), v.end());
	    for(int i = 0; i< n; i++)
	    {
	        if(v[i].second != i)
	        {
	            swap(v[i].first, v[v[i].second].first);
	            swap(v[i].second, v[v[i].second].second);
	            swaps++;
	        }
	        if(v[i].second != i)
	            i--;
	    }
	
	    return swaps;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends