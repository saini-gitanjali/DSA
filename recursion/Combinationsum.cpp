// { Driver Code Starts



#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution 
{
    public:
    void backtrack(vector<int> &cand, int start, int target, vector<int> curr, vector<vector<int>> &result) {
        if(target<0)
            return;
        if(target == 0)
            result.push_back(curr);
        for(int i=start; i<cand.size(); i++)
        {
            curr.push_back(cand[i]);
            backtrack(cand, i, target - cand[i], curr, result);
            curr.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &a, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        
        backtrack(a, 0, target, curr, result);
        return result;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends