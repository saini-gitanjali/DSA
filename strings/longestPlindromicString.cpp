// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
       
       int len = 1;
       int low, high, start = 0;
       for(int i=1; i<S.length();i++)
       {
           low = i-1;
           high = i;
           while(low >= 0 && high < S.length()&&(S[low] == S[high]))
           {
                   if(len < high-low+1){
                       start = low;
                        len = high-low+1;
                       
                   }
               low--;
               high++;
           }
           
           low = i-1;
           high = i+1;
           while(low>=0 && high < S.length() && (S[low] == S[high]))
           {      
                   if(len < high-low+1){
                        start = low;
                       len = high-low+1;
                    //   cout<<len<<endl;
                   }
               
               low--;
               high++;
           }
       }
       int n = start+len-1;
        string ans = "";
       for(int  i =start; i<=n; i++)
        ans += S[i];
    
    return ans;
       
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends