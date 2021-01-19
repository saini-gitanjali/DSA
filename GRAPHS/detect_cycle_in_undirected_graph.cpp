// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
    bool detectCycle(int node, vector<int> adj[],  bool visited[], int parent)
    {
        
        visited[node] = true;
        for(auto nbr : adj[node])
        {
            if(!visited[nbr])
            {
                if(detectCycle(nbr, adj, visited, node))
                    return true;
            }
            else if(nbr!=parent){           //if a node can be visited from more than one parent it contans a cycle
               // cout<<"nbr "<<nbr<<"parent "<<parent;
                return true;
            }
        }
            return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    //int parent = -1;
	    bool *visited =  new bool[V];
	    for(int i=0; i<V; i++)
	        visited[i] = false;
	    for(int i=0; i<V; i++)
	    { 
	        if(!visited[i])
	         {   if(detectCycle(i, adj, visited, -1))
	                return true;
	         }
	    }
	   return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends