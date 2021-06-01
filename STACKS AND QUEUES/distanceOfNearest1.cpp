// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	   int r = grid.size(), c = grid[0].size();
	   vector<vector<int>> v(r, vector<int>(c,INT_MAX));
	   queue<pair<int , int>> q;
	   
	   
	   for(int i=0; i<r; i++)
	    for(int j=0; j<c; j++)
	        if(grid[i][j] == 1)
	        {
	            q.push({i, j});
	            v[i][j] = 0;
	        }
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	   while(!q.empty())
	   {
	       int x = q.front().first , y = q.front().second , newX, newY;
	       q.pop();
	       for(int k = 0; k < 4; k++)
	       {
	           int newx = x + dx[k];
	           int newy = y + dy[k];
	           if(newx >= 0 && newx < r && newy >= 0 && newy < c && v[newx][newy] > v[x][y]+1){
	                v[newx][newy] = v[x][y]+1;
	                q.push({newx, newy});
	               
	           }
	       }
	       
	   }
	   return v;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends