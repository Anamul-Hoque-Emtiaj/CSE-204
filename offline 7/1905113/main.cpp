#include<iostream>
#include <cstdlib>
#include <algorithm>
#include<fstream>
#include <iomanip>
#include<chrono>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(int arr[], int n)
{
    int key,j;
    for(int i=1; i<n; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0&&key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void merged(int arr[], int l, int m,int h)
{
    int n = h-l+1;
    int temp[n];
    int c=0,i=l,j=m+1;
    while(i<=m&&j<=h)
    {
        if(arr[i]<arr[j])
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



int partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l-1;

    for(int j=l; j<h; j++)
    {

        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[h]);
    return i+1;
}

void quickSort(int arr[], int l, int h)
{
    if(l<h)
    {
        int m = partition(arr,l,h);
        quickSort(arr,l,m-1);
        quickSort(arr,m+1,h);
    }
}

int RQS_Partition(int arr[], int l, int h)
{
    int random = l+rand()%(h-l);
    swap(arr[random], arr[h]);
    int pivot = arr[h];
    int i = l-1;

    for(int j=l; j<h; j++)
    {

        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[h]);
    return i+1;
}

void RandomizedQuickSort(int arr[], int l, int h)
{
    if(l<h)
    {
        int m = RQS_Partition(arr,l,h);
        RandomizedQuickSort(arr,l,m-1);
        RandomizedQuickSort(arr,m+1,h);
    }
}


int main()
{
    int nArr[] = {5,10,100,1000,10000},n,nSize=5;
    double times[nSize][7]; //total times(of 20 iteration) of 7 Sorts for 6 different value of n
    for(int i=0; i<nSize; i++)
        for(int j=0; j<7; j++)
            times[i][j] = 0;


    for(int i=0; i<nSize; i++)
    {
        n = nArr[i];
        int *randomInput = new int[n];
        for(int j=1; j<=20; j++)
        {
            //merge sort
            srand(i+1234+j);
            for(int it=0; it<n; it++)
                randomInput[it] = rand();

            auto start = chrono::high_resolution_clock::now();
            mergedSort(randomInput,0,n-1);
            auto stop = chrono::high_resolution_clock::now();
            times[i][0]+= (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count()/1000000.0;

            //quick sort
            srand(i+1234+j);
            for(int it=0; it<n; it++)
                randomInput[it] = rand();

            start = chrono::high_resolution_clock::now();
            quickSort(randomInput,0,n-1);
            stop = chrono::high_resolution_clock::now();
            times[i][1]+= (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count()/1000000.0;


            //RandomizedQuickSort
            srand(i+1234+j);
            for(int it=0; it<n; it++)
                randomInput[it] = rand();

            start = chrono::high_resolution_clock::now();
            RandomizedQuickSort(randomInput,0,n-1);
            stop = chrono::high_resolution_clock::now();
            times[i][2]+= (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count()/1000000.0;


            //insertion sort
            srand(i+1234+j);
            for(int it=0; it<n; it++)
                randomInput[it] = rand();

            start = chrono::high_resolution_clock::now();
            insertionSort(randomInput,n);
            stop = chrono::high_resolution_clock::now();
            times[i][3]+= (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count()/1000000.0;


            //quick sort for sorted array
            start = chrono::high_resolution_clock::now();
            quickSort(randomInput,0,n-1);
            stop = chrono::high_resolution_clock::now();
            times[i][4]+= (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count()/1000000.0;


            //RandomizedQuickSort for sorted array
            start = chrono::high_resolution_clock::now();
            RandomizedQuickSort(randomInput,0,n-1);
            stop = chrono::high_resolution_clock::now();
            times[i][5]+= (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count()/1000000.0;


            //STL sort
            srand(i+1234+j);
            for(int it=0; it<n; it++)
                randomInput[it] = rand();

            start = chrono::high_resolution_clock::now();
            sort(randomInput,randomInput+n);
            stop = chrono::high_resolution_clock::now();
            times[i][6]+= (double)chrono::duration_cast<chrono::nanoseconds>(stop - start).count()/1000000.0;
        }
        delete []randomInput;
    }

    ofstream output;
    output.open("out.csv");

    output<<fixed<<setprecision(6);
    output<<",,,Time Required in ms\n";
    output<<"n,Merge Sort,Quicksort,Randomized Quicksort,Insertion Sort,Quicksort with Sorted Input,Randomized Quicksort with Sorted Imput,STL sort() function\n";


    for(int i=0; i<nSize; i++)
    {
        output<<nArr[i]<<",";
        for(int j=0; j<7; j++)
            output<<(1.00*times[i][j]/20)<<",";
        output<<endl;
    }
    output.close();
    cout<<"Done\n";
}
