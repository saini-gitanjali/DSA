// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
     int i, j, n = a.length();
      set<char> s;
      for(int i=0; i<n; i++)
        s.insert(a[i]);
    for(i=0; i<n; i++)
    {
        
        s.erase(a[i]);
        if(s.empty())
            break;
        char ch = *s.begin();
        if(ch < a[i])
        {
         char ch2 = a[i];
            for(j=0; j<n; j++)
            {
                if(a[j] == ch2)
                    a[j] = ch;
                else if(ch == a[j])
                    a[j] = ch2;
            }
            break;
        }
    }
    return a;
      
      
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends