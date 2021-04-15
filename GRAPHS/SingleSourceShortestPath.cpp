//single source shortest path problem for unweighted graph
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iterator>

using namespace std;

void addEdge(vector<int> adj_list[], int v, int u)
{
    adj_list[u].push_back(v);
    //comment below line for directed graph
    adj_list[v].push_back(u);
}

int* SingleSourceShortestPath(vector<int> adjList[], int V, int src, int dist[])
{
    queue<int> q;
    vector<int> bfs;
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
    {    
        visited[i] = 0;
        dist[i] = 0;
    }
    q.push(src);
    visited[src]=1;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(!visited[curr])
            visited[curr] =1;
        for(auto u : adjList[curr]) {
            if(visited[u]==0) {
                q.push(u);
                visited[u] = 1;
                dist[u] = dist[curr]+1;
                
            }
        }
    }
    return dist;
}

void print(vector<int> vec[], int V){
    
    for(int i=0; i<V; i++)
    {
        cout<<i<<": ";
        for(auto x:vec[i])
            cout<<x<<" ";
        cout<<endl;
    }
}

int main(){
    
    int V=10000,E;
    cin>>V;
    
    vector<int> adj_list[V];
    cin>>E;
    int s, d;
    for(int i=0; i<E; i++)
    {
        cin>>s>>d;
        addEdge(adj_list, s, d);
    }
    print(adj_list, V);
    int src;
    int *dist = new int[V];
        cin>>src;
    SingleSourceShortestPath(adj_list, V, src, dist);
    cout<<"\nvertex\tdistance from source"<<endl;
    for(int i=0; i<V; i++) 
        cout<<src<<"\t\t"<<dist[i]<<endl;
    return 0;
}