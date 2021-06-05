#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minCost(vector<int> &x, vector<int> &y, int n, int m)
{
    int horizontal_pieces = 1; 
    int vertical_peices = 1;
    int i = 0, j = 0, min_Cost = 0; 
    sort(x.begin(), x.end(), greater<int>());
    sort(y.begin(), y.end(), greater<int>());
    while(i<n && j<m) {
        if(x[i] > y[j])
        {
            min_Cost += x[i] * vertical_peices;
            horizontal_pieces++;
            i++;
        }
        else {
            min_Cost += y[j] * horizontal_pieces;
            vertical_peices++;
            j++;
        }
    }
    int total = 0;
    
    while(i<n){
        total += x[i];
        i++;
    }
    min_Cost += total * vertical_peices ;
    total = 0;
    while( j < m) {
        total += y[j];
        j++;
    }
    min_Cost += total * horizontal_pieces;
    return min_Cost;
}

int main() {
    int n, m, a;
    cin>>n>>m;
    vector<int> x(m);
    vector<int> y(n);
    
    for(int i=0; i<n; i++)
    {
        cin>>a; 
        x.push_back(a);
    }
    for(int i=0; i<m; i++)
    {
        cin>>a;
        y.push_back(a);
    }

    cout<<minCost(x, y, n, m);
    return 0;
}