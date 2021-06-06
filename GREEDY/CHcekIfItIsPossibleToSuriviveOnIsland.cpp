#include<iostream>
#include<math.h>

using namespace std;
int main()
{
    int n , s, m, totalFood = 0, validDays = 0, sundays = 0, days = 0;
    cin>>n>>s>>m;
    totalFood = m*s;
    sundays = ceil(s/7);
    validDays = s - sundays;
    days = ceil(totalFood/validDays);
    if(days < validDays)
        cout<<"YES "<<days<<endl;
    else
        cout<<"NO";
    return 0;

}