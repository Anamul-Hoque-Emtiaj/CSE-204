#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll a,i,j;
    cin>>a;
    ll dp[a+1];
    dp[0] = 0;
    dp[1] = 1;
    for(i=2; i<=a; i++)
    {
        ll mini = 600000;
        for(j = 1; j*j<=i; j++)
        {
            mini = min(mini,dp[i-j*j]+1);
        }
        dp[i] = mini;
    }
    cout<<dp[a]<<endl;
}

