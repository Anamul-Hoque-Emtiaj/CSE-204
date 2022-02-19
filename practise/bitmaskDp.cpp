#include<iostream>
#include<cmath>
using namespace std;

int *DP_Table,**w;

//set 1 at pos'th bit of n and return updated n
int setOne(int num,int pos)
{
    return num | (1<<pos);
}

//check, is pos'th bit of n contain 1
bool isOne(int num,int pos)
{
    return (bool)(num & (1<<pos));
}

//set 0 at pos'th bit of n and return updated n
int setZero(int num,int pos)
{
    return num ^ (1<<pos);
}

int minimumCost(int n)
{
    for(int i=0; i<(1<<n); i++)
    {
        if(DP_Table[i]!=-1)
            continue;
        int ans = 1000000000;
        for(int j=0; j<n; j++)
        {
            if(isOne(i,j))
            {
                int s=0;
                for(int k=0; k<n; k++)
                {
                    if(isOne(i,k))
                    {
                        s += w[j][k];
                    }
                }
                s += DP_Table[setZero(i,j)];
                ans = min(s,ans);
            }
        }
        DP_Table[i] = ans;
    }
    return DP_Table[(1<<n)-1];
}



int main()
{
    int n;
    cin>>n;

    DP_Table = new int [1<<n];
    for(int i=0; i<(1<<n); i++)
    {
        DP_Table[i] = -1;
    }

    w = new int*[n];
    for(int i=0; i<n; i++)
        w[i] = new int[n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>w[i][j];
            if(i==j)
                DP_Table[setOne(0,i)] = w[i][j];
        }
    }


    cout<<minimumCost(n)<<endl;
    /*for(int i=0; i<(1<<n); i++)
    {
        cout<<DP_Table[i]<<" ";
    }*/

    for(int i=0; i<n; i++)
    {
        delete w[i];
    }
    delete []DP_Table;
    delete []w;
}

