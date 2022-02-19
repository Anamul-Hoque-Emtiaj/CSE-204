#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool cmp(ll &a, ll &b)
{
    return a>b;
}

int main()
{
    ll n,k,x,i,res=0;
    cin>>n>>k>>x;
    ll arr[n];
    for(i=0; i<n; i++)
        cin>>arr[i];
    sort(arr,arr+n,cmp);
    arr[0]*=pow(x,k);
    for(i=0; i<n; i++)
    {
        res = res | arr[i];
    }
    cout<<res<<endl;
}


