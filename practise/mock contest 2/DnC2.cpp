#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ifstream input;
ofstream output;

list<ll> DnC2(list<ll> v, ll depth)
{
    ll s = ceil(v.size()*1.00/2.00);
    ll s1 = v.size();
    list<ll> l,r,p,q;
    if(s <= depth)
    {
        for(ll i=1; i<=s; i++)
        {
            l.push_back(v.front());
            //cout<<v.front()<<" ";
            v.pop_front();
        }
        //cout<<endl;
        return l;
    }
    for(ll i=1; i<=s; i++)
    {
        l.push_back(v.front());
        v.pop_front();
    }
    for(ll i=s+1; i<=s1; i++)
    {
        r.push_back(v.front());
        v.pop_front();
    }
    p = DnC2(l,depth);
    q = DnC2(r,depth);
    while(!q.empty())
    {
        p.push_back(q.front());
        q.pop_front();
    }
    return p;
}

void divide(ll n)
{
    list<ll> v,r;
    for(ll i=1; i<=n; i++)
        v.push_back(i);
    ll m =  ceil(log2(n));
    for(ll i=1; i<=m; i++)
    {
        r = DnC2(v,ceil(n*1.00/(pow(2,i))));
        output<<r.size()<<" ";
        while(!r.empty())
        {
            output<<r.front()<<" ";
            r.pop_front();
        }
        output<<endl;
    }
}

int main()
{
    input.open("input.txt");
    output.open("output.txt");
    ll n;
    input>>n;
    output<<ceil(log2(n))<<endl;
    divide(n);
}
