// { Driver Code Starts

#include <iostream>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    
    int countSquares(int N) {
    int count = 0;
        for(int  i = 1; i < sqrt(N); i++)
            {
                if(i*i < N)
                    count++;
    }
    return  count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends