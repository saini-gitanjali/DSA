#include<iostream>
#include<unordered_map>
using namespace std;

void commonElements(int **matrix, int m ,int n) {
    unordered_map<int, int> mp;
    int i =0 ,   j =0;
    for ( int j = 0; j < n; j++)
        mp[matrix[0][j]] = 1;
    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j< n; j++)
        {
            if(mp[matrix[i][j]] == i) 
            {
                mp[matrix[i][j]] = i+1;
                if( i== m-1 && mp[matrix[i][j]] == m)
                    cout<<matrix[i][j]<<" ";
            }
        }

    }  
}

int main(){
    int n, m;
    cin>>n>>m;
    int **matrix = new int *[n];
    for(int i = 0; i<n; i++)
        matrix[i] = new int[m];
    for(int i =0; i<n; i++)
        for(int j= 0 ; j < m;  j++)
            cin>>matrix[i][j];
    
    commonElements(matrix, n, m);
    return 0;
}