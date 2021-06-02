#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    // int t[10^3][10^3];
    
    int lcsUtility(int x, int y, string &s1, string &s2, int t[1000][1000]){
        
        if(t[x][y] != -1)
            return t[x][y];
            
        if(x == 0 || y == 0)
             t[x][y] = 0; 
        
        else 
        {   
            if(s1[x-1] == s2[y-1])
                return t[x][y] = 1 + lcsUtility(x-1, y-1, s1, s2, t);
            else
                return t[x][y] = max(lcsUtility(x-1, y, s1, s2, t), lcsUtility(x, y-1, s1, s2,t));
        }    
        return t[x][y];
        
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        int t[1000][1000];
        memset(t, -1, sizeof(t));
        return lcsUtility(x, y, s1, s2, t); 
        
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends