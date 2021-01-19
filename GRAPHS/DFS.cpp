// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
vector <int> dfs(vector<int> g[], int N)
{
    vector<int> visited(N,0);
   vector<int> dfs;
   stack<int> st;
   if(N)
        st.push(0);
   //visited[0]=1;
 
   while(!st.empty())
   {
        int y=st.top();
        st.pop();
        if(visited[y]!=1)
        {
            dfs.push_back(y);
            visited[y]=1;
        }
        for(int i=g[y].size()-1; i>=0; i--)
            if(!visited[g[y][i]])
                st.push(g[y][i]);
   }
   return dfs;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends