// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int prime = 101;
    long long createHash(string p , int n){
        long long hash = 0;
        for(int i = 0; i <= n; i++)
            hash += p[i]*pow(prime,i);
        return hash;
        
    }
    
    long long recalculateHash(string t, int oldIndex, int newIndex, long long oldHash, int patLen) {
       long long newHash = oldHash - t[oldIndex];
        newHash = newHash/prime;
        newHash = newHash + t[newIndex]* pow(prime, patLen-1);
        return newHash;
    }
    
    bool checkEqual(string t, int start1, int end1, string p, int start2, int end2) {
       
        if(end1 - start1 != end2 - start2)
            return false;
            
        while(start1 <= end1 && start2 <= end2) {
                if(t[start1] != p[start2])
                    return false;
            start1++;
            start2++;
            
        }
        
        return true;
    }
    
        vector <int> search(string pat, string txt)
        {
            int i;
            vector<int> v;
            int m = pat.length();
            int n = txt.length();
            
            long long patHash = createHash(pat, m-1);
            long long txtHash = createHash(txt, m-1);
            
            for( i = 1; i <= n - m + 1; i++)
            {
                if(patHash == txtHash && checkEqual(txt, i-1 , i + m - 2, pat, 0, m-1))
                        v.push_back(i);
                if(i < n - m + 1) {
                    
                    txtHash = recalculateHash(txt, i - 1, i + m  - 1, txtHash, m);
                   
                }
                    
            }
            
            if(v.size() == 0)
            {
                v.push_back(-1);
            }
         return v;
         
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends