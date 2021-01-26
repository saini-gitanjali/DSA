#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<iterator>
#include<list>
#include<set>

using namespace std;

unordered_map<int, list<pair<int, int> > > adjList;
unordered_map <int, int> dist;
void addEdge(int src, int dest, int weight, bool bidirectional = true)
{
    adjList[src].push_back(make_pair(dest, weight));
    if(bidirectional)
        adjList[dest].push_back(make_pair(src, weight));
}

void dijkstra(int V, int src)
{
    //first element will be distance as elements will be sorted according to fist element of pair
    for(auto j: adjList) 
        dist[j.first] = INT16_MAX;
    set<pair<int, int> > s;         //set to find\ node at a min distance from source
    // initialization
    dist[src] = 0;      //distance of any node from itself is zero
    s.insert(make_pair(0, src)); 
    while(!s.empty()) {
        auto curr = *(s.begin());
        int node = curr.second;
        int currDist = curr.first;
        s.erase(s.begin());
        for(auto child: adjList[node]) {
            if(currDist + child.second < dist[child.first]) {
                int temp = child.first;
                auto f = s.find(make_pair(dist[temp], temp));
                if(f != s.end()) {
                    s.erase(f);
                }
                dist[temp] = child.second+currDist;
                s.insert(make_pair(dist[temp], temp));
            }
        } 
    }
    for (auto d : dist)
        {
            cout<<d.first<<"\t"<<d.second<<endl;
        }
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
    dijkstra( V, src);
    return 0;
}