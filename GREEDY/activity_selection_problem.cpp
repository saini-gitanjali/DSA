/*You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person,
assuming that a person can only work on a single activity at a time.*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool utilitysort(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
}
int main()
{
    vector<pair<int,int>> activity, ans;
    int n, st, fn;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>> st>>fn;
        activity.push_back(make_pair(st,fn));
    }
    sort(activity.begin(), activity.end(), utilitysort); 
    ans.push_back(activity[0]);
    for(int i=1;i<n; i++)
    { 
        int s=ans.size();
        if((activity[i].first>ans[s-1].second)||activity[i].first==ans[s-1].second)
            ans.push_back(activity[i]);
    }
    for(auto x:ans)
        {
            cout<<x.first<<" "<<x.second;
            cout<<endl;
        }
}