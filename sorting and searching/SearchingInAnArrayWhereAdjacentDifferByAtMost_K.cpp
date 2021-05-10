#include<iostream>
using namespace std;
 
int search(int arr[], int n, int k, int x) {
   int i = 0;
    while(i<n) {
        if(arr[i] == x)
            return i;
        i = i + max(1, abs(arr[i]-x)/k);
    }
}

int main() {
    int n, k, arr[10000], x;
    cin>>n;
    cin>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>x;
    cout<<search(arr,n, k, x);
    return 0;
}