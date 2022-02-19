#include<iostream>
using namespace std;

void merged(int arr[], int l, int m,int h)
{
    int n = h-l+1;
    int temp[n];
    int c=0,i=l,j=m+1;
    while(i<=m&&j<=h)
    {
        if(arr[i]>arr[j])
            temp[c++] = arr[i++];
        else
            temp[c++] = arr[j++];
    }
    while(i<=m)
    {
        temp[c++] = arr[i++];
    }
    while(j<=h)
    {
        temp[c++] = arr[j++];
    }
    for(i=0; i<n; i++)
        arr[l+i] = temp[i];
}

///descending sort with merge sort
void mergedSort(int arr[], int l, int h)
{
    if(l<h)
    {
        int m = (l+h)/2;
        mergedSort(arr,l,m);
        mergedSort(arr,m+1,h);
        merged(arr,l,m,h);
    }
}

int main()
{
    int N,K,i;
    long long int result=0;
    cin>>N>>K;
    int plants[N];
    for(i=0; i<N; i++)
        cin>>plants[i];

    mergedSort(plants,0,N-1);
    for(i=0; i<N; i++)
    {
        result+=((i/K)+1)*plants[i];
    }
    cout<<result<<endl;
}
