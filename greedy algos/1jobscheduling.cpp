// { Driver Code Starts
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int *start = new int[n];
        int *end = new int[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        maxMeetings(start, end, n);
        cout << endl;
    }
    return 0;
}// } Driver Code Ends
struct meeting{
    int index, s, f;
    
};
bool utilitysort(meeting a, meeting b) 
{ 
    return (a.f < b.s); 
}

void maxMeetings(int start[], int finish[], int n) {
    meeting arr[1000];
    for(int i=0;i<n;i++){
        arr[i].index = i;
        arr[i].s = start[i];
        arr[i].f = finish[i];
    }
    sort(arr,arr+n,utilitysort);
    int j =0;
    cout<<arr[j].index+1<<" ";
    for(int i=1;i<n;i++)
    {
        if(arr[j].f<=arr[i].s)
            cout<<arr[i].index+1<<" ";
            j=i;
    }
    
}
