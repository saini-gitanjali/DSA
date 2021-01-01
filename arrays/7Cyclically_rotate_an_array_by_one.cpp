//problem link : https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0
#include<iostream>
using namespace std;
int main()
{
	//code
	int t;
	cin>>t;
	while(t)
	{
		int n;
		cin>>n;
		int a[10000];
		for(int i=0; i<n; i++)
			cin>>a[i];
		int x = a[n - 1], i;
		for (i = n - 1; i > 0; i--)
		a[i] = a[i - 1]; 
		a[0] = x;
		for(int i=0; i<n; i++)
			cout<<a[i]<<" ";
		cout<<endl;
		t--;
	}
	return 0;
}