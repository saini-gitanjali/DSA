// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    
    #define pii pair<int, int>
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        
      queue<pii> rotten;
      int fresh = 0, num = 0, r = grid.size(), c = grid[0].size(), count=0; 
        
        for(int i = 0; i < r; i++)
            for(int j  = 0; j < c; j++)
                if(grid[i][j] == 2)
                    rotten.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
        
        while(!rotten.empty())  {
           num = rotten.size();
            for(int i = 0; i < num; i++) {
                   int x = rotten.front().first, y  = rotten.front().second;
                 rotten.pop();
                if( x > 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    rotten.push({x-1, y});
                    fresh--;
                }
                if( x < r-1 && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    rotten.push({x + 1, y});
                    fresh--;
                }
                if( y > 0 && grid[x][y-1] == 1) {
                    grid[x][y - 1] = 2;
                    rotten.push({x, y-1});
                    fresh--;
                }
                if(y < c-1 && grid[x][y+1] == 1)
                {
                    grid[x][y+1] = 2;
                    fresh--;
                    rotten.push({x, y+1});
                }
            }
            if(!rotten.empty())
                count++;
        }
        // int ans = 0;
        
    return fresh == 0 ? count : -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends