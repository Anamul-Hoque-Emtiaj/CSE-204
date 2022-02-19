#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll i,n;
    cin>>n;
    ll h[n],cost[n];
    for(i=0; i<n; i++)
        cin>>h[i];
    cost[0] = 0;
    if(n>=2)
        cost[1] = abs(h[1] - h[0]);
    for(i=2; i<n; i++)
    {
        cost[i] = min(cost[i-1]+abs(h[i] - h[i-1]),cost[i-2]+abs(h[i] - h[i-2]));
    }
    cout<<cost[n-1]<<endl;
}


