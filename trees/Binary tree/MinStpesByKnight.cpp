// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find out minimum visited Knight needs to reach target position.
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    int visited[1001][1001];    
	    queue<pair<int, int> > q;
	    int moves = -1;
	    
	    for(int i=0; i<n; i++)
	        for(int j=0; j<n;j++)
	            visited[i][j] = 0;
	    
	    int x1 = KnightPos[0];
	    int y1 = KnightPos[1];
	    int x2 = TargetPos[0];
	    int y2 = TargetPos[1];
	    
	    //if target and destination position are same
	    if(x1 == x2 && y1 == y2)
	        return 0;
	    vector<int> dx = {2, 2, -2, -2, 1, 1, -1, -1};
        vector<int> dy = {1, -1, 1, -1, 2, -2, 2, -2};
	    q.push({x1-1, y1-1});
	   
	    visited[x1-1][y1-1] = 1;
	   
	    while(!q.empty()) {
	       int size = q.size();
	       moves++;
	       for(int k = 0; k < size; k++)
	       {
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            if(x == TargetPos[0]-1 && y == TargetPos[1]-1)
                    return moves;
    	       for(int i=0; i<8; i++)
    	       {
        	       int xx = x + dx[i];
        	       int yy = y + dy[i];
        	       
        	       if(xx < 0 || yy < 0 || xx > n || yy > n || visited[xx][yy] == 1)
        	            continue;
        	       
        	       visited[xx][yy] = 1;
        	       q.push({xx, yy});
    	       }
	        }
	   }
	   
	        
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends