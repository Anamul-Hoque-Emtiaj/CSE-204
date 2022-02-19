#include<iostream>
using namespace std;

int **DP_Table;

int LCS(int n, int m, string &s1, string &s2)
{
    if(n<0 || m<0)
        return 0;
    if(DP_Table[n][m]!=-1)
        return DP_Table[n][m];

    if(s1[n]==s2[m])
    {
        DP_Table[n][m] = 1 + LCS(n-1,m-1,s1,s2);
    }
    else
    {
        DP_Table[n][m] = max(LCS(n,m-1,s1,s2),LCS(n-1,m,s1,s2));
    }
    return DP_Table[n][m];
}

int LCSiTerative(int n, int m, string &S1, string &S2)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                DP_Table[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                DP_Table[i][j] = DP_Table[i - 1][j - 1] + 1;
            else
                DP_Table[i][j] = max(DP_Table[i - 1][j], DP_Table[i][j - 1]);
        }
    }
    return DP_Table[n][m];
}

///reconstruct LCS using backtracking
void printLCS(int n, int m, string &s1, string &s2)
{
    if(n<0 || m<0)
        return ;

    if(s1[n]==s2[m])
    {
        printLCS(n-1,m-1,s1,s2);
        cout<<s1[n];
    }
    else
    {
        if(n==0)
            printLCS(n,m-1,s1,s2);
        else if(m==0)
            printLCS(n-1,m,s1,s2);
        else if(DP_Table[n-1][m]>DP_Table[n][m-1])
            printLCS(n-1,m,s1,s2);
        else
            printLCS(n,m-1,s1,s2);
    }
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int l1 = s1.length();
    int l2 = s2.length();

    DP_Table = new int* [l1+1];
    for(int i=0; i<=l1; i++)
        DP_Table[i] = new int[l2+1];

    for(int i=0; i<=l1; i++)
        for(int j=0; j<=l2; j++)
            DP_Table[i][j] = -1;

    int result = LCSiTerative(l1,l2,s1,s2);
    cout<<result<<endl;
    printLCS(l1,l2,s1,s2);
    cout<<endl;

    for(int i=0; i<=l1; i++)
    {
        for(int j=0; j<=l2; j++)
            cout<<DP_Table[i][j]<<" ";
        cout<<endl;
    }

    for(int i=0; i<=l1; i++)
        delete DP_Table[i];
    delete []DP_Table;
}
