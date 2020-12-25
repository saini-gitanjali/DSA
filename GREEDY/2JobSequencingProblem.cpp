// problem link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
///*Given a set of N jobs where each job i has a deadline and profit associated to it. 
//Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
//We earn the profit if and only if the job is completed by its deadline.
//The task is to find the maximum profit and the number of jobs done.*/

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


bool comparator(struct Job a,struct Job b){
    return a.profit>b.profit;
}

pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    int count=0, profit=0;
    sort(arr, arr+n, comparator);
    bool slots[n];
    memset(slots, 0, sizeof(slots));
    for(int i=0; i<n; i++)
        for(int j=min(arr[i].dead-1, n); j>=0; j--)
        {
            if(slots[j]==0){
                slots[j] = 1;
                profit += arr[i].profit;
                count++;
                break;
            }
        }
        return make_pair(count,profit);
    
} 

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
        //function call
        pair<int,int> ans = JobScheduling(arr, n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
	return 0; 
}


  // } Driver Code Ends