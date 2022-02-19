#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll merged(ll arr[], ll l, ll m, ll h)
{
    ll n = h-l+1;
    ll temp[n];
    ll c=0,i=l,j=m+1,in=0;
    while(i<=m&&j<=h)
    {
        if(arr[i]<=arr[j])
            temp[c++] = arr[i++];
        else
        {
            temp[c++] = arr[j++];
            in+=(m - i + 1);
        }
    }
    while(i<=m)
    {
        temp[c++] = arr[i++];
    }
    while(j<=h)
    {
        temp[c++] = arr[j++];
    }
    for(i=0; i<n; i++)
        arr[l+i] = temp[i];
    return in;
}

ll mergedSort(ll arr[], ll l, ll h)
{
    ll r=0;
    if(l<h)
    {
        ll m = (l+h)/2;
        ll r1 = mergedSort(arr,l,m);
        ll r2 = mergedSort(arr,m+1,h);
        ll r3 = merged(arr,l,m,h);
        r = r1 + r2 + r3;
    }
    return r;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        ll arr[n];
        for(i=0; i<n; i++)
            cin>>arr[i];
        cout<<mergedSort(arr,0,n-1)<<endl;
    }
}
