#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int v, e;
    cin>>v>>e;
    vector<int> graph[v+1];
    vector<int> indegree(v+1, 0);
    vector<int> ans(v+1, 0);
    queue<int> q;

    for(int i=0; i<e; i++) {
        int s, d;
        cin>>s>>d;
        graph[s].push_back(d);
        indegree[d]++;
    }
    for(int i=1; i<=v; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
            ans[i] = 1;
        }
    }
    while(!q.empty()) {
        int val = q.front();
        q.pop();
        for(auto x : graph[val])
        {
            indegree[x]--;
            if(indegree[x] == 0)
            {
                
                q.push(x);
                ans[x] = ans[val] + 1;
                  
            }
            // q.push(x); 
        }

    }
    for(int i=1; i<=v; i++)
        cout<<ans[i]<<" ";
    return 0;
} 