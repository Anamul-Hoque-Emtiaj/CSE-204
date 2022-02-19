#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct task
{
    ll a,d;
};

bool cmp(struct task &s1, struct task &s2)
{
    return s1.a<s2.a;
}

int main()
{
    ll n;
    cin>>n;
    struct task t[n];
    for(ll i=0; i<n; i++)
        cin>>t[i].a>>t[i].d;
    sort(t,t+n,cmp);
    ll c=0,r=0;
    for(ll i=0; i<n; i++)
    {
        c+=t[i].a;
        r+=(t[i].d-c);
    }
    cout<<r<<endl;
}


