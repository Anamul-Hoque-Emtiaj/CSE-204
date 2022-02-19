#include<iostream>
#define ll long long int
using namespace std;

int main()
{
    ll t, n, a, b, c, d, e, f,i,j=1;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>e>>f>>n;
        ll arr[n+6];
        arr[0] = a% 10000007;
        arr[1] = b% 10000007;
        arr[2] = c% 10000007;
        arr[3] = d% 10000007;
        arr[4] = e% 10000007;
        arr[5] = f% 10000007;
        arr[6] = (a + b + c + d + e + f)% 10000007;;
        for(i=7; i<=n; i++)
        {
            ll x  = arr[i-1] - arr[i-7] + arr[i-1];
            if(x<0)
                arr[i] = (x + 10000007)% 10000007;
            else
                arr[i] = x% 10000007;
        }
        printf("Case %d: %d\n", j, arr[n]);
        j++;
    }
}
