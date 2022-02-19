#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,i,t;
    cin>>n;

    vector<pair<ll,ll>> v;
    for(i=1; i<=n; i++)
    {
        cin>>t;
        pair<ll,ll> p;
        p.first = t;
        p.second = i+1;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    ll prev = LONG_MAX;
    ll c=0;
    for(ll i=0; i<n; i++)
    {
        if(v[i].second < prev)
        {
            c++;
        }
        prev = v[i].second;
    }
    cout<<c<<endl;
}

