#include<iostream>
#include<algorithm>
using namespace std;

class Edge {
    public:
        int src;
        int dest;
        int weight;
};

bool compare(Edge e1, Edge e2){
    return e1.weight <= e2.weight;
}

int findParent(int v, int *parent) {
    if(parent[v] == v)
        return v;
    return findParent(parent[v], parent);
} 

void printMST(Edge *MST, int V) {
    int MSTweight = 0;
    cout<<"THE SPANNING TREE IS :"<<endl;
    for(int i = 0; i < V-1; i++) {
        if(MST[i].src < MST[i].dest)
            cout<<MST[i].src<<" "<<MST[i].dest<<" "<<MST[i].weight<<endl;
        else if(MST[i].src > MST[i].dest)
            cout<<MST[i].dest<<" "<<MST[i].src<<" "<<MST[i].weight<<endl;
        MSTweight += MST[i].weight;
    }
    cout<<"\n MST weight is : "<<MSTweight;
}

void kruskal(Edge *input, int V, int E){
    Edge *MST = new Edge[V-1];
    sort(input, input+E, compare);
    int *parent = new int[V];
    int count = 0, i = 0;
    for(int i = 0; i < V; i++)
        parent[i] = i;                      //initially every node is it's parent
    while(count != V-1) {
        Edge currentEdge = input[i];
        int sourceParent  = findParent(currentEdge.src, parent);
        int destParent = findParent(currentEdge.dest, parent);
        if(sourceParent != destParent) {
            MST[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
    printMST(MST, V);
}

int main() {
    int V, E;
    Edge *input = new Edge[V];
    cout<<"\nEnter number of vertices and edges in the graph : ";
    cin>>V>>E;
    for(int i = 0; i < E; i++){
        int s, d, w;
        cin>>s>>d>>w;
        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    kruskal(input, V, E);
    return 0;
}