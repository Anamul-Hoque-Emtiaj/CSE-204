#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    string s;
    cin>>s;
    ll i,j,m,n;
    n = s.size();
    ll arr[n];
    arr[0] = 0;
    for(i=1; i<n; i++)
    {
        if(s[i]==s[i-1])
            arr[i] = arr[i-1] + 1;
        else
          arr[i] = arr[i-1];
    }
    cin>>m;
    while(m--)
    {
        ll l,r,c;
        cin>>l>>r;
        c = arr[r-1] - arr[l-1];
        cout<<c<<endl;
    }
}

