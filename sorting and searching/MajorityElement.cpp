// { Driver Code Starts
#include<iostream>
#include<unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < size; i++)
            mp[a[i]]++;
        for(auto  i : mp) {
            if(i.second > size/2)
                return i.first;
        }
        return -1;

    }

};
int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[10000];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends