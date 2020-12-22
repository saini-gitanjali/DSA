#include<iostream>
using namespace std;

int fisrt_binarySearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n-1;
    int index =-1;
    while(low<high){
        int mid = (high+low)/2;
        if(x < arr[mid])    high = mid-1;
        else if(x > arr[mid])    low = mid+1;
        else
        {
            index = mid;
            high = mid-1;
        } 
    }
    return index;

}

int last_binarySearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n-1;
    int index =-1;
    while(low<high){
        int mid = (high+low)/2;
        if(x < arr[mid])    high = mid-1;
        else if(x > arr[mid])    low = mid+1;
        else{
            index = mid;
            low = mid+1;
        } 
    }
    return index;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        int target;
        
        cin>>n>>target;
        int *arr = new int[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        int first =fisrt_binarySearch(arr, n, target);
        int last =  last_binarySearch(arr, n, target);
        if(first == -1)
            cout<<first<<endl;
        else
        cout<<first<<" "<<last<<endl;
    }
    
}