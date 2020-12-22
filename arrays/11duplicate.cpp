#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                return nums[i];
        }
        return -1;
    }
    int main()
    {
        int n;
        int m;
        vector<int> v;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>m;
            v.push_back(m);
        }
        cout<<findDuplicate(v);
    return 0;
    }
