/*
   This code can be compiled and run ok.

   This is to let user inpur several number
   then use insertion sort and merge sort to sort them in in ascending order

   usage:
     H34086254_hw3.cpp

   input files:
     no inputfile

   output files:
     no outputfile

   compile:
     g++ -o H34086254_hw3 H34086254_hw3.cpp

   pseudocode:
        for i=0 to n
            input>>A[i]
        printout A
        copy A to B
        =======================
        sort A by insertion sort
        for j=2 to n
            do key=A[j]
            i=j-1
            while i>0 and a[i]>key
                do A[i+1]=A[i]
                i=i-1
            A[i+1]=key
        =======================
        printout A
        check if A is in ascending order
        =======================
        sort B by merge sort
        Merge(B,m,p,n)
        n1 = p ¡V m + 1
        n2 = n ¡V p
        for i=1 to n1
            do L[i]=A[m+i¡V1]
        for j=1 to n2
           do R[j]=A[p+j]
        L[n1+1] = Max„V
        R[n2+1] = Max„V
        i=1
        j=1
        for k=m to n
            do if L[i] <= R[j]
                    then A[k] = L[i]
                    i=i+1
               else
                    A[k] = R[j]
                    j=j+1
        =======================
        printout B
        check if B is in ascending order

   coded by CHEN,HONG-YIN, ID: H34086254, email: h34086254@ncku.edu.tw
   date: 2020.10.11
*/
#include<iostream>
#include<limits.h>
using namespace std;
void printout_array(double A[],int m,int n);

void duplicate_array(double A[],double B[],int m,int n);

void ins_sort(double A[],int m,int n);

void is_ascending(double A[],int n);

void mg_sort(double B[],int m,int n);

void merge(double B[],int m,int p,int n);

int main(){
    int n;
    int m=0;
    cout<<"Please input n:"<<endl;
    cin>>n;
    double*A;
    A=new double [n];
    double*B;
    B=new double [n];
    cout<<"Please input "<<n<<" real numbers:"<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    printout_array(A,m,n);
    duplicate_array(A,B,m,n);
    ins_sort(A,m,n);
    cout<<"By insertion sort:"<<endl;
    printout_array(A,m,n);
    is_ascending(A,n);
    mg_sort(B,m,n-1);//0 6
    cout<<"By merge sort:"<<endl;
    printout_array(B,m,n);
    is_ascending(B,n);
}

void printout_array(double A[],int m,int n){
    for(int i=m;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void duplicate_array(double A[],double B[],int m,int n){
    for(int i=m;i<n;i++){
        B[i]=A[i];
    }
}

void ins_sort(double A[],int m,int n){
    for(int j=1;j<n;j++){
        double key=A[j];
        int i=j-1;
        while(i>=0&&A[i]>key){
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
    }
}

void is_ascending(double A[],int n){
    int ascending;
    for(int j=0;j<n;j++){
        for(int i=j+1;i<n;i++){
            if(A[j]<=A[i]){
                ascending=1;
            }
            else{
                ascending=0;
                break;
            }
        }
    }
    if(ascending==1){
        cout<<"Great!! It is in ascending order!!"<<endl;
    }
    if(ascending==0){
        cout<<"Warning!! The order is NOT ascending!!"<<endl;
    }
}


void mg_sort(double B[],int m,int n){
    if(n>m){
        int p=((m+n)/2);
        mg_sort(B,m,p);
        mg_sort(B,p+1,n);
        merge(B,m,p,n);
    }
}

void merge(double B[],int m,int p,int n){
    int n1=0;
    int n2=0;
    n1=p-m+1+1;//"+1"build a space for max
    n2=n-p+1;
    double L[n1];
    double R[n2];
    for(int i=0;i<(n1-1);i++){
        L[i]=B[m+i];
    }
    for(int j=0;j<(n2-1);j++){
        R[j]=B[p+j+1];
    }
    L[n1-1]=LONG_MAX;
    R[n2-1]=LONG_MAX;
    int i=0,j=0;
    for(int k=m;k<=n;k++){
        if(L[i]<R[j]){
            B[k]=L[i];
            i++;
        }
        else{
            B[k]=R[j];
            j++;
        }
    }
}
