// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void keypad(string output, string k[], vector<string> &res, int a[], int n) {
        if(n-1<0){
            res.push_back(output);
            return;
        }
        int n1 = a[n-1];
        string s = k[n1];
        for(int i=0; i<s.length(); i++)
            keypad(s[i]+output, k, res, a, n-1);
        
    }
    vector<string> possibleWords(int a[], int N)
    {
        string output = "";
        string k[] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };;
        vector<string> res;
        keypad(output, k, res, a, N);
        sort(res.begin(), res.end());
        return res;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends