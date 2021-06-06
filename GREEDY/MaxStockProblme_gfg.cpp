// In a stock market, there is a product with its infinite stocks. 
// The stock prices are given for N days, where arr[i] denotes the price of the stock on the ith day.
//  There is a rule that a customer can buy at most i stock on the ith day. If the customer has an 
// amount of k amount of money initially, find out the maximum number of stocks a customer can buy.
// In a stock market, there is a product with its infinite stocks. The stock prices are given for N days,
//  where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy 
// at most i stock on the ith day. If the customer has an amount of k amount of money initially, 
// find out the maximum number of stocks a customer can buy.

#include<iostream>
#include<vector>
#include<utility>
#include<math.h>
#include<algorithm>

using namespace std;

int maxStocks(vector<int> &price, int n, int amount) {
    int stocks = 0, p, s;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; i++)
        v.push_back({price[i], i+1});
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        p = v[i].first;
        s = v[i].second;
        if(p * s <= amount)
        {
            stocks += s;
            amount -= p * s;
        }
        else
        {
            stocks += (amount/(p));
            amount -= amount/(p);
        }
    }
    
    
    return stocks;
}

int main() {
    int n, amount = 0;
    vector<int> price;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        price.push_back(x);
    }
    cin>>amount;
    cout<<maxStocks(price, n, amount);
    return 0;
}