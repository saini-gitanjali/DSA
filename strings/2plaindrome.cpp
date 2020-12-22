 #include <iostream>
using namespace std;

class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    int ans=1;
	    int i=S.length()-1;
	    int j=0;
	    while(j<=i)
	    {
	        if(S[i--]!=S[j++])
	        {
	            return 0;
	        }
	        
	        
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() 
{
   	
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends