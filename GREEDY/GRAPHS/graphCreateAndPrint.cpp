#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

void addEdge(vector<int> adj_list[], int v, int u)
{
   // cout<<u<<v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);

}
void print(vector<int> vec[], int V){
    for(int i=0; i<V; i++)
    {
        cout<<i<<"->";
        for(auto x:vec[i])
            cout<<x<<"->";
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
   /* addEdge(adj_list, 0, 1);
    addEdge(adj_list, 0, 2);
    addEdge(adj_list, 0, 3);
    addEdge(adj_list, 1, 2);
    addEdge(adj_list, 1, 3);
    addEdge(adj_list, 2, 3);
 */ print(adj_list, V);
    return 0;
}