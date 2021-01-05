//sort and array using heapsort
#include<iostream>

using namespace std;

void heapify(int arr[], int i,  int n){
    //cout<<"heapify";
    int max=i, l, r;
    l = 2*i+1;
    r = 2*i+2;
    if(l<n && arr[max] < arr[l])
        max = l;
   //else max =i;
    if(r<n && arr[max] <  arr[r])
        max = r;
    if(max != i){
        swap(arr[max], arr[i]);
    heapify(arr, max, n);
    }
}

void heapsort(int arr[], int n)
{
    for(int i = n/2-1; i>=0; i--){
        heapify(arr, i, n);
    }
   
    for(int i = n-1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    heapsort(arr, n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
