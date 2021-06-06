#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

    int maxProduct(vector<int>& nums) {
            int result = 1, count0 = 0, count_neg = 0, max_neg = INT16_MIN;
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<nums.size(); i++)
        // cout<<nums[i]<<" ";
        // cout<<endl;
        for(int i=0;i<nums.size(); i++)
        {
            
            if(nums[i] == 0)
            {
                count0++;
                continue;
                
            }
            if(nums[i] < 0)
            {
                max_neg = max(max_neg, nums[i]);
                count_neg++;
                result *= nums[i];
            }
            else
                result *= nums[i];
        }

        if(count0 == nums.size())
            return 0;
        if(count0 == nums.size()-2 && count_neg == 1)
            return 0;
        if(result < 0)
            return result/nums[0];
        else return result;
    }

int main()
{
    int n, x;
    vector<int> nums;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        nums.push_back(x);

    }

    cout<<maxProduct(nums);
    return 0;
}
