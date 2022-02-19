#include<bits/stdc++.h>
using namespace std;

int a[1000];
int fib(int n)
{
    if(n<2)
        return n;
    if(a[n]!=-1)
        return a[n];
    a[n]=fib(n-1)+fib(n-2);
    return a[n];
}

int main()
{
    int n,r;
    cin>>n;
    a[0] = 0;
    a[1] = 1;
    for(int i=2;i<=n;i++)
        a[i]=-1;
    r=fib(n);
    cout<<r<<endl;
    for(int i=0;i<=n;i++)
        cout<<a[i]<<" ";
}
