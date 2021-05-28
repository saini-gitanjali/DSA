// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    // bool compare ()
    int maxMeetings(int start[], int end[], int n)
    {
        int i;
        vector<pair<int, pair<int, int>>> meetings;
        for( i = 0; i < n; i++)
            meetings.push_back(make_pair(end[i], make_pair(start[i], i)));
        
        sort(meetings.begin(), meetings.end());
        int count = 1;
        int curr =meetings[0].first;
        
        for(int i = 1; i < n; i++) {
            if(curr <  meetings[i].second.first)
            {
                count++;
                curr = meetings[i].first;
                
            }
        }
        return count;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends