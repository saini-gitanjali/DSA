#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int sum(vector<int> &arr, int k)
{
    deque<int> dq;
    int min = INT_MAX, max = INT_MAX;
    for (int i = 0, j=0; i < arr.size(), j>k; i++, j++)
        dq.push_back(arr[i]);
    for(int )
    
}
int main() {
    int count, k;
    cin>>count;
    vector<int> array(count);
    for (int i = 0; i < count; i++)
        cin>>array[i];
    cin>>k;
    cout<<sum(array, k);
    return 0;
}