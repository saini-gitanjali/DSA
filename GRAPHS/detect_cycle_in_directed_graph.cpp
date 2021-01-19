// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends





class Solution {
public:
    bool DFS(int v, vector<int>adj[], bool vis[],bool recStack[])
    {
        vis[v] = true;
        recStack[v] = true;
        for(auto i: adj[v])
        {
            if((!vis[i])&&DFS(i, adj, vis, recStack))
                return true;
            else if(recStack[i])
                return true;
        }
        recStack[v] = false;
        return false;
    }
    
	bool isCyclic(int V, vector<int> adj[]) {
	    bool *recStack = new bool[V];
	    bool *vis = new bool[V];
	    for (int i = 0; i < V; ++i) {
        vis[i] = false;
        recStack[i] = false;
    }
	    
	    for(int i=0; i<V; i++)
	    {   
	        if(!vis[i]&&DFS(i, adj, vis, recStack))
	            return true;
	   
	    }
	    return false;
	}
};


// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends