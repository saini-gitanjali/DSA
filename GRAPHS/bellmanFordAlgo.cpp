#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<iterator>
#include<list>
#include<set>

using namespace std;

unordered_map<int, pair<int, int>> adjList;
unordered_map <int, int> dist;
void addEdge(int src, int dest, int weight, bool bidirectional = true)
{
    adjList[src] = make_pair(dest, weight);
    if(bidirectional)
        adjList[dest] = make_pair(src, weight);
}

void bellmanFord(int V, int E, int src)
{
    //    int *dist = new int[V];
    //    for(int i=0; i < V; i++)
    //         dist[i] = 0;
    //     dist[src] = 0;
    // for(int i = 1; i<V-1; i++)
    //     for(int j = 0; j < E; j++)
    //     {
    //         int u = adjList[j].first;
    //         int v = adjList[j].second;


    //     }
}

void print(int V) {  
    for(auto x: adjList) {
        cout<<x.first<<"-> ";          //display soruce node for edge
          for(auto l: x.second)                   //iterate over list in map for dest node and weight of that edge
            cout<<"("<<l.first<<" "<<l.second<<"), ";             //l.first = dest node, l.second = weight of src and dest
        cout<<endl;
    }
}

int main(){
    int V=10000,E, w, s, d;
    cin>>V>>E;    
    bool bidirectional;
    cin>>bidirectional;

        for(int i=0; i<E; i++)
        {
            cin>>s>>d>>w;
            addEdge(s, d, w, bidirectional);
        }
    cout<<"\n The adjacency list of graph is: \n";
    print(V);
    int src;
    int *dist = new int[V];
        cin>>src;
        cout<<adjList[0].first<<" "<<adjList[0].second;
    bellmanFord( V, E, src);
    return 0;
}