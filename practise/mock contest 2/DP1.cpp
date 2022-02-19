#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll a[2005][2005];

ll edit_distance(string s1, string s2, ll n, ll m)
{
    if(a[n][m]!=-1)
        return a[n][m];

    if(s1[n-1]==s2[m-1])
    {
        a[n][m] = edit_distance(s1,s2,n-1,m-1);
    }
    else
    {
        ll sub, in, de;
        in = 1 + edit_distance(s1,s2,n,m-1);
        de = 1 + edit_distance(s1,s2,n-1,m);
        sub = 1 + edit_distance(s1,s2,n-1,m-1);
        a[n][m] = min(in, min(de,sub));
    }
    return a[n][m];
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        ll n = s1.size();
        ll m = s2.size();
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=m; j++)
            {
                if(i==0)
                {
                    a[i][j] = j;
                }
                else if(j==0)
                {
                    a[i][j] = i;
                }
                else
                {
                    if(s1[i-1]==s2[j-1])
                    {
                        a[i][j] = a[i-1][j-1];
                    }
                    else
                    {
                        a[i][j] = 1 + min(a[i-1][j-1],min(a[i][j-1],a[i-1][j]));
                    }
                }
            }
        }
        cout<<a[n][m]<<endl;
    }
}

