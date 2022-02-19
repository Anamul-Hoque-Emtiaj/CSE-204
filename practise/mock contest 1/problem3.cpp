#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,i,mx,r;
    cin>>n;
    ll arr[n];
    for(i=0; i<n; i++)
        cin>>arr[i];

    mx = 1;
    r = 1;
    for(i=1; i<n; i++)
    {

        if(arr[i] < arr[i-1])
        {
            mx = max(mx,r);
            r=1;
        }
        else
        {
            r++;
        }
    }
    cout<<mx<<endl;
}
