#include<bits/stdc++.h>
using namespace std;

int n,W,v[100],w[100],DP_Table[100][100],f[100]= {0};
/*int knapsake(int i,int j)
{
    if(i==0||j==0)
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    int mx=0,c,k;
    if(j>=w[i-1])
    {
        c=v[i-1]+knapsake(i-1,j-w[i-1]);
        if(c>mx)
            mx=c;
    }
    c=knapsake(i-1,j);
    mx=max(c,mx);
    t[i][j]=mx;
    return t[i][j];
}*/

int knapSackDP()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                DP_Table[i][j] = 0;
            else if (w[i - 1] <= j)
                DP_Table[i][j] = max(v[i - 1]
                          + DP_Table[i - 1][j - w[i - 1]],
                          DP_Table[i - 1][j]);
            else
                DP_Table[i][j] = DP_Table[i - 1][j];
        }
    }

    return DP_Table[n][W];
}

void reconstract(int i,int j)
{
    if(i==0||j==0)
        return;
    if(DP_Table[i][j]==DP_Table[i-1][j])
        reconstract(i-1,j);
    else if(DP_Table[i][j]==(DP_Table[i-1][j-w[i-1]]+v[i-1]))
    {
        f[i-1]=1;
        reconstract(i-1,j-w[i-1]);
    }
}

int main()
{
    int i,r,j;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>v[i];
    for(i=0; i<n; i++)
        cin>>w[i];
    cin>>W;
    for(i=0; i<100; i++)
        for(j=0; j<100; j++)
        {
            if(i==0||j==0)
                DP_Table[i][j]=0;
            else
                DP_Table[i][j]=-1;
        }
    r=knapSackDP();
    reconstract(n,W);
    cout<<r<<endl;
    for(i=0; i<n; i++)
    {
        if(f[i]==1)
            cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
            cout<<DP_Table[i][j]<<" ";
        cout<<endl;
    }
}
