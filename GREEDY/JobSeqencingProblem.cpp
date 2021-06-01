// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends

/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> res;
        sort(arr, arr+n, [](Job &a, Job &b){
            return a.profit > b.profit;
        });
        
        int profit = 0;
        int count = 0;
        vector<int> slots(n, -1);
        
        for(int i = 0; i < n; i++) {
            for(int j = arr[i].dead-1; j >= 0; j--)
            {
                if(slots[j] == -1)                                  //check if slot is empty and if empty , the job can be done
                {
                    
                    profit += arr[i].profit;
                    slots[j] = arr[i].id;
                    count++;
                    break;
                }
            }
            
        }
        res.push_back(count);
        res.push_back(profit);
        return res;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends