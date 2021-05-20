#include<iostream>

using namespace std;

 

int median(int *arr1, int *arr2, int n1, int n2)
{
   int i = 0, j = 0, k = 0;
   int size = n1+n2;
   int *arr3 =  new int[n1+n2];
    while (i < n1 && j< n2)
    {
        if(arr1[i] <= arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else if(arr1[i] > arr2[j]){
            arr3[k++] = arr2[j++];
        }
    }
    while(i<n1)
        {
            arr3[k++] = arr1[i++];
        }
    while(j<n2)
    {
        arr3[k++] = arr2[j++];
    }
    int mid = size/2, ans = 0;
    if(size%2 == 0)
    {
        int sum = arr3[mid] + arr3[mid - 1];
        ans = sum/2;
    }
    else
        ans = arr3[mid];
    
    return ans;
}

int main() {
    int n1, n2, *arr1, *arr2;
     cin>>n1;
    cin>>n2;

    arr1 = new int[n1];
    arr2 = new int[n2];
   

    for(int i = 0; i< n1; i++)
        cin>>arr1[i];

    for(int i = 0; i< n2; i++)
        cin>>arr2[i];
    
    cout<<median(arr1, arr2, n1, n2);
    return 0;
}