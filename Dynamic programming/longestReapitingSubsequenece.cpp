// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		   int len = str.length();
		   int dp[len+1][len+1];
		 
		   memset(dp, 0, sizeof(dp));
		   
		   for(int i=1; i <= len; i++)
		   {
		       for(int j=1; j <= len; j++)
		        {
		            
		               if(str[i-1] == str[j-1] && i!=j)
                            dp[i][j] = dp[i-1][j-1]+1;
                        else
                            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                            
		        }
		   }
		   
		return dp[len][len];
		    
		}
		

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends