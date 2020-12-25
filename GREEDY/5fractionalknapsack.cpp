// problem link: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

// function to return fractionalweights
bool compare(Item a, Item b){
    return ((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight);
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr+n, compare);
    double max_value = 0.0;
    double curr_weight = 0.0;
    for(int i=0; i<n; i++){
        if(curr_weight +arr[i].weight<=W){
            curr_weight += arr[i].weight;
            max_value += arr[i].value;
        }
        else if(curr_weight < W){
            int remaining_weight = W-curr_weight;
            max_value += arr[i].value * (double)remaining_weight/(double)arr[i].weight;
            break;
            
        }
        else if(W==0)
            break;
    }
    return max_value;
}

// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends