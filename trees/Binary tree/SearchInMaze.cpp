// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> path;
    
    void solve(int i, int j, vector<vector<int> > &m , int n,string s, vector<vector<int>> &visited)
    {
        if(i < 0 || j<0 || i>=n || j>= n)
            return;
        if(m[i][j] == 0 || visited[i][j] == 1)      //if the path is already visited or it is blocked
            return;
        if(i == n-1 && j == n-1)        //if all the paths are explored we have the ans in s
        {
            path.push_back(s);
            return;
        }
        
        visited[i][j] = 1;
        solve(i-1, j, m, n, s+'U', visited);
        solve(i+1, j, m, n, s+'D', visited);
        solve(i, j+1, m, n, s+'R', visited);
        solve(i, j-1, m, n, s+'L', visited);
        visited[i][j] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> visited(n , {0});
        if(m[0][0] == 0)
            return path;
        string s = "";
        solve(0, 0, m, n,s, visited);
        sort(path.begin(), path.end());
        return path;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends