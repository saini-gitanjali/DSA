// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <iostream>
#include<unordered_set>
using namespace std;

bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}

// O(n^2) solution
// //Complete this function
// bool subArrayExists(int arr[], int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if(sum == 0)
//                 return true;
//         }
//         sum = 0;   
//     }    
//     return false;
// }

// O(n) solution
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sumSet;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sumSet.find(sum) != sumSet.end() || sum == 0)
            return true;
        sumSet.insert(sum);
    }
    return false;
}