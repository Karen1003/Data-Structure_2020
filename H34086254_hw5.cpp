/*
   This code can be compiled and run ok.

   This is to let user input a natual number n, a lower bound a_min, an upper bound a_max
   then the program will randomly generate n numbers which are between a_min and a_max.
   Last,sort these numbers by heap sort and quick sort.

   usage:
     H34086254_hw5.cpp

   input files:
     no inputfile

   output files:
     no outputfile

   compile:
     g++ -o H34086254_hw5 H34086254_hw5.cpp

   pseudocode:
    input n,a_min,a_max,seed
    for i=0 to n
        A[i]=rand() % (a_max-a_min+1)+a_min
    copy A to B
    =======================
    sort A by heap sort
    MAX-HEAPIFY(A,i,n)
    l ← LEFT(i )=2i
    r ← RIGHT(i )=2i+1
    int largest=i;
    if l ≤ n and A[l] > A[i]
        then largest =l
    if r ≤ n and A[r] > A[largest]
        then largest =r
    if largest ≠ i
        swap (A[i],A[largest])
        MAX-HEAPIFY(A, largest, n)

    heap_sort(A,n)
    for i=n/2-1 to i=0
        max_heapify(A,i,n);

    for i=n-1 to i=0
        swap(A[0],A[i]);
        max_heapify(A,0,i);
    =======================
    printout A
    =======================
    sort B by quick sort
    PARTITION(B, p, n)
    pivot =B[n]
    i=p-1
    for j=p to n-1
        do if B[ j ] ≤ pivot
            i++
            swap(B[i],B[j])
    swap(B[i+1],B[r])
    return i + 1

    quick_sort(B,p,n){
    if(p<n)
        int pi=partition(B,p,n)
        quick_sort(B,p,pi-1)
        quick_sort(B,pi+1,n)
    =======================
        printout B

   coded by CHEN,HONG-YIN, ID: H34086254, email: h34086254@ncku.edu.tw
   date: 2020.11.18
*/
#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

void duplicate_array(int A[],int B[],int m,int n);

void printout_array(int A[],int m,int n);

void max_heapify(int A[],int i,int n);

void heap_sort(int A[],int n);

int partition(int B[],int p,int n);

void quick_sort(int B[],int p,int n);

int main(){
    int n,a_min, a_max;
    int seed=0;
    int m=0;
    int p=1;
    cout<<"Please input [n, a_min, a_max,seed]: "<<endl;
    cin>>n>>a_min>>a_max>>seed;
    int *A;
    A=new int [n];
    int *B;
    B=new int [n];
    if(seed==0){
        srand((unsigned)(time(NULL))) ;
    }
    else{
        srand(seed);
    }
    for(int i=0;i<n;i++){
        A[i]=rand() % (a_max-a_min+1)+a_min;
    }
    printout_array(A,m,n);
    duplicate_array(A,B,m,n);
    heap_sort(A,n);
    cout<<"By heap sort:"<<endl;
    printout_array(A,m,n);
    quick_sort(B,p-1,n-1);
    cout<<"By quick sort:"<<endl;
    printout_array(B,m,n);
}


void printout_array(int A[],int m,int n){
    for(int i=m;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void duplicate_array(int A[],int  B[],int m,int n){
    for(int i=m;i<n;i++){
        B[i]=A[i];
    }
}

void max_heapify(int A[],int i,int n){
    int largest=i;
    int l=i*2+1;
    int r=i*2+2;
    if(l<n&&A[l]>A[largest])
        largest=l;
    if(r<n&&A[r]>A[largest])
        largest=r;
    if(largest!=i){
        swap(A[i],A[largest]);
        max_heapify(A,largest,n);
    }
}

void heap_sort(int A[],int n){
    for(int i=n/2-1;i>=0;i--){
        max_heapify(A,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(A[0],A[i]);
        max_heapify(A,0,i);
    }
}

int partition(int B[],int p,int n){
    int pivot=B[n];
    int i=p-1;
    for(int j=p;j<=n-1;j++){
        if(B[j]<pivot){
             i++;
             swap(B[i],B[j]);
        }
    }
    swap(B[i+1],B[n]);
    return (i+1);
}

void quick_sort(int B[],int p,int n){
    if(p<n){
        int pi=partition(B,p,n);
        quick_sort(B,p,pi-1);
        quick_sort(B,pi+1,n);
    }
}
