// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of islands.
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &vis, int n,int m)
    {
        if(i < 0 || j<0 || i >=n || j>=m)
            return ;
            
        if(grid[i][j] == '0')
            return ;
        if(!vis[i][j])
        {
            vis[i][j] = 1;
        
            dfs(grid, i+1, j, vis, n, m );
            dfs(grid, i-1, j, vis, n, m );
            dfs(grid, i+1, j, vis, n, m );
            dfs(grid, i, j+1, vis, n, m );
            dfs(grid, i, j-1, vis, n, m );
            dfs(grid, i+1, j+1, vis, n, m );
            dfs(grid, i-1, j-1, vis, n, m );
            dfs(grid, i+1, j-1, vis, n, m );
            dfs(grid, i-1, j+1, vis, n, m );
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size(), m = grid[0].size(), islands = 0;
        vector<vector<int>> vis( n , vector<int> (m, 0));
        
        for(int i=0; i<n;i++)
            for(int j=0; j<m; j++)
                vis[i][j] = 0;
            
        for(int i = 0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(grid, i, j, vis, n, m);
                    islands++;
                }
            }
            
     return islands;   
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends