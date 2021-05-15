// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long int arr[],long long int left, long long int mid, long long int right) {
         long long int temp[right];
        long long int  i = left, j = mid, k = left, count = 0;
        long long int nl = mid+1-left;
        long long int nr = right - mid;
        
        while(i <= mid-1 && j <= right) {
            if(arr[i] <= arr[j]){
                temp[k] = arr[i];
                k++;
                i++;
            }
            else {
                temp[k] = arr[j];
                k++;
                j++;
                count = count + mid - i; 
            }
        }
        while(i <= mid-1) {
            temp[k] = arr[i];
            k++;
            i++;
        }
        while(j <= right) {
            temp[k] = arr[j];
            k++;
            j++;
        }
        for(long long int m = left; m <= right; m++)
            arr[m] = temp[m];
        return count;
    }
    
    long long int mergesort(long long int arr[],  long long int left, long long int right) {
        
        long long int mid = 0, inv_count = 0; 
        if(right > left) {
            mid = left + (right - left)/2;
            inv_count += mergesort(arr, left, mid);
            inv_count += mergesort(arr, mid+1, right);
            
            inv_count +=  merge(arr, left, mid+1,  right);
        }
        return inv_count;    
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return mergesort(arr, 0, N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends