#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n,m,k,i,j,c=0;
    cin>>n>>m>>k;
    list<ll> a,b;
    for(i=0; i<n; i++)
    {
        cin>>j;
        a.push_back(j);
    }
    for(i=0; i<m; i++)
    {
        cin>>j;
        b.push_back(j);
    }
    a.sort();
    b.sort();
    while(!a.empty() && !b.empty())
    {
        if(abs(a.front()-b.front())<=k)
        {
            c++;
            a.pop_front();
            b.pop_front();
        }
        else
        {
            if(a.front()<b.front())
                a.pop_front();
            else
                b.pop_front();
        }
    }
    cout<<c<<endl;
}
