#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, c=0,i,j;
    cin>>n;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        c+=a[i];
    }

    int DP_Table[n][n];
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            if(i==j)
            {
                if(a[i]==1)
                    DP_Table[i][j] = c - 1;
                else
                    DP_Table[i][j] = c + 1;
            }
            else
            {
                if(a[j]==1)
                    DP_Table[i][j] = DP_Table[i][j-1] - 1;
                else
                    DP_Table[i][j] = DP_Table[i][j-1] + 1;
            }
        }
    }
    int mx = INT_MIN;
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            mx = max(mx,DP_Table[i][j]);
        }
    }
    cout<<mx<<endl;
}
