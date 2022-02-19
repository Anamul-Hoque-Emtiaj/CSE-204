#include<iostream>
#include<cmath>
using namespace std;

int **DP_Table,**w;

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

//return cost for completing the traveling from current index(city)
int Cost(int i, int num, int n)
{
    if(DP_Table[i][num]!=-1)
        return DP_Table[i][num];

    int c = 0;
    for(int j=0; j<n; j++)
        if(isOne(num,j)==true)
            c+=w[i][j];

    if (num == (1<<n)-1)
        return DP_Table[i][num] = c;

    int ans = 1000000000;
    for(int j=0; j<n; j++)
    {
        if(isOne(num,j)==false)
        {
            int result = Cost(j,setOne(num,j),n) + c;
            ans = min(ans, result);
        }
    }
    return DP_Table[i][num] = ans;
}

//return minimum cost of traveling
int optimalCost(int n)
{
    int ans = 1000000000;

    for(int i=0; i<n; i++)
    {
        int result = Cost(i,setOne(0,i),n);
        ans = min(ans, result);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    w = new int*[n];
    for(int i=0; i<n; i++)
        w[i] = new int[n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>w[i][j];

    DP_Table = new int* [n];
    for(int i=0; i<n; i++)
        DP_Table[i] = new int[1<<n];
    for(int i=0; i<n; i++)
        for(int j=0; j<pow(2,n); j++)
            DP_Table[i][j] = -1;

    cout<<optimalCost(n)<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<pow(2,n); j++)
            cout<<DP_Table[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0; i<n; i++)
    {
        delete DP_Table[i];
        delete w[i];
    }
    delete []DP_Table;
    delete []w;
}
