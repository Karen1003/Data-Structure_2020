/*
   This code can be compiled and run ok.

   This is to generate seven different sort(insertion sort,merge sort,heap sort,quick sort,counting sort,radix sort,and bucket sort),
   then count the time.
   usage:
     H34086254_hw6.cpp

   input files:
     input.txt

   output files:
     results.txt

   compile:
     ./run_all.bat

   pseudocode:
       inout>>is_p>>n>>a_min>>a_max>>seed;
       do insertion sort
        print time
       do merge sort
        print time
       do heap sort
        print time
       do quick sort
        print time
       do counting sort
        print time
       do radix sort
        print time
       do bucket sort
        print time
    ===============================
       sort A by insertion sort
            for j=2 to n
                do key=A[j]
                i=j-1
                while i>0 and A[i]<key
                    do A[i+1]=A[i]
                    i=i-1
                A[i+1]=key
    ===============================
        sort A by merge sort
            Merge(A,m,p,n)
            n1 = p - m + 1+ 1
            n2 = n - p + 1
            for i=1 to n1
                do L[i]=A[m+i]
            for j=1 to n2
               do R[j]=A[p+j+1]
            L[n1+1] = LONG_MIN
            R[n2+1] = LONG_MIN
            i=1
            j=1
            for k=m to n
                do if L[i] >= R[j]
                        then A[k] = L[i]
                        i=i+1
                   else
                        A[k] = R[j]
                        j=j+1
    ===============================
        sort A by heap sort
        min_heapify(A,i,n)
        l ← LEFT(i )=2i
        r ← RIGHT(i )=2i+1
        int smallest=i;
        if l ≤ n and A[l] < A[i]
            then smallest =l
        if r ≤ n and A[r] < A[largest]
            then smallest =r
        if samllest ≠ i
            swap (A[i],A[smallest])
            min_heapify(A, smallest, n)

        heap_sort(A,n)
        for i=n/2-1 to i=0
            min_heapify(A,i,n);

        for i=n-1 to i=0
            swap(A[0],A[i]);
            min_heapify(A,0,i);
    ===============================
        sort A by quick sort
        PARTITION(A, p, n)
        pivot =A[n]
        i=p-1
        for j=p to n-1
            do if A[ j ]>= pivot
                i++
                swap(A[i],A[j])
        swap(A[i+1],A[r])
        return i + 1

        quick_sort(A,p,n){
        if(p<n)
            int pi=partition(A,p,n)
            quick_sort(A,p,pi-1)
            quick_sort(A,pi+1,n)
    ===============================
        sort A by counting sort

        int *C;
        C=new int [n];

        int x=A[0];

        for j=1 to n
            if A[j] > x
                x=A[j]

        int *D;
        D=new int [x+1];

        for i=0 to x
            D[i] = 0

        for j=0 to n-1
            D[A[j]]++

        for i=x-1 down to 0
            D[i]+=D[i+1]

        for i=n-1 down to 0
            C[D[A[i]]-1] = A[i]
            D[A[i]]--

        for j=0 to n
            A[j] = C[j]
    ===============================
        sort A by radix sort
        int getMax(int A[],int n){
        int max =A[0];
        for i=1 to n
            if (A[i]>max)
                max=A[i];
        return max;
        }

        void countSort(int A[],int n,int exp){

        int *C;
        C=new int [n];


        int *D;
        D=new int [10];

        for i=0 to 9
            D[i] = 0;


        for j=0 to n
            D[(A[j]/exp)%10]++;


        for i=8 down to 0
            D[i]+=D[i+1];

        for i=n-1 down to 0
        C[D[(A[i]/exp)%10]-1] = A[i];
        D[(A[i]/exp)%10]--;


        for j=0 to n-1
        A[j] = C[j];

    }

    void radixsort(int A[],int n){

        int M=getMax(A,n);
        for (int exp = 1; M / exp > 0; exp *= 10){
            countSort(A, n, exp);
        }
    }
    ===============================
        sort A by bucket sort

        int max=A[0];
        int min=A[0];
        int exp=1;

        for i=0 to n-1
            if(A[i]>max)
                max=A[i];


        for i=0 to n-1
            if(A[i]<min)
                min=A[i];


        vector<int> b[10];

        for i=0 to n-1
            int bi=((float) A[i]/max)*9
            b[bi].push_back(A[i])


        for i=0 to 9
            sort(b[i].begin(), b[i].end(),greater<int>());

        int index=0;
            for i=9 down to 0
                for (int j = 0; j < b[i].size(); j++)
                    A[index] = b[i][j];
                    index++;

   coded by CHEN,HONG-YIN, ID: H34086254, email: h34086254@ncku.edu.tw
   date: 2020.12.29
*/
#include<iostream>
#include <cstdlib>
#include<ctime>
#include<limits.h>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <vector>

using namespace std;

void duplicate_array(int A[],int B[],int m,int n);

void printout_array(int A[],int m,int n);

clock_t my_timer();

void is_A_desc(int A[],int n);

void ins_sort(int A[],int m,int n);

void mg_sort(int A[],int m,int n);

void merge(int A[],int m,int p,int n);

void min_heapify(int A[],int i,int n);

void heap_sort(int A[],int n);

int partition(int A[],int p,int n);

void quick_sort(int A[],int p,int n);

void counting_sort(int A[],int n);

void radixsort(int A[],int n);

int getMax(int A[],int n);

void countSort(int A[],int n,int exp);

void bucketSort(int A[], int n);



int main(){
    int is_p,n,a_min, a_max;
    int seed=0;
    int m=0;
    int p=1;
    time_t START,END;
    //cout<<"Please input [is_p, n, a_min, a_max,seed]: "<<endl;
    cin>>is_p>>n>>a_min>>a_max>>seed;
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
    if(is_p==1){
        printout_array(A,m,n);
        cout<<endl;
    }
    duplicate_array(A,B,m,n);

    START = my_timer();
    ins_sort(A,m,n);
    END = my_timer();
    cout << "insertion sort:"<<(END*1. - START)/CLOCKS_PER_SEC <<"s" << " ";
    if(is_p==1){
        cout<<"By insertion sort:"<<endl;
        printout_array(A,m,n);
        is_A_desc(A,n);
    }


    duplicate_array(B,A,m,n);
    START = my_timer();
    mg_sort(A,m,n-1);
    END = my_timer();
    cout << "merge sort:"<<(END*1. - START)/CLOCKS_PER_SEC <<"s" << " ";
    if(is_p==1){
        cout<<"By merge sort:"<<endl;
        printout_array(A,m,n);
        is_A_desc(A,n);
    }

    duplicate_array(B,A,m,n);
    START = my_timer();
    heap_sort(A,n);
    END = my_timer();
    cout << "heap sort:"<<(END*1. - START)/CLOCKS_PER_SEC <<"s" << " ";
    if(is_p==1){
        cout<<"By heap sort:"<<endl;
        printout_array(A,m,n);
        is_A_desc(A,n);
    }


    duplicate_array(B,A,m,n);
    START = my_timer();
    quick_sort(A,p-1,n-1);
    END = my_timer();
    cout << "quick sort:"<<(END*1. - START)/CLOCKS_PER_SEC <<"s" << " ";
    if(is_p==1){
        cout<<"By quick sort:"<<endl;
        printout_array(A,m,n);
        is_A_desc(A,n);
    }



    duplicate_array(B,A,m,n);
    START = my_timer();
    counting_sort(A,n);
    END = my_timer();
    cout << "counting sort:"<<(END*1. - START)/CLOCKS_PER_SEC <<"s" << " ";
    if(is_p==1){
        cout<<"By counting sort:"<<endl;
        printout_array(A,m,n);
        is_A_desc(A,n);
    }


    duplicate_array(B,A,m,n);
    START = my_timer();
    radixsort(A,n);
    END = my_timer();
    cout << "radix sort:"<<(END*1. - START)/CLOCKS_PER_SEC <<"s" << " ";
    if(is_p==1){
        cout<<"By radix sort:"<<endl;
        printout_array(A,m,n);
        is_A_desc(A,n);
    }


    duplicate_array(B,A,m,n);
    START = my_timer();
    bucketSort(A,n);
    END = my_timer();
    cout << "bucket sort:"<<(END*1. - START)/CLOCKS_PER_SEC <<"s" << " ";
    if(is_p==1){
        cout<<"By bucket sort:"<<endl;
        printout_array(A,m,n);
        is_A_desc(A,n);
    }
    cout<<endl;
}


clock_t my_timer(){
   return clock();
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

void is_A_desc(int A[],int n){
    int desc;
    for(int j=0;j<n;j++){
        for(int i=j+1;i<n;i++){
            if(A[j]>=A[i]){
                desc=1;
            }
            else{
                desc=0;
                break;
            }
        }
    }
    if(desc==1){
        cout<<"Great!! It is in descending order!!"<<endl;
    }
    if(desc==0){
        cout<<"Warning!! The order is NOT descending!!"<<endl;
    }
}

void ins_sort(int A[],int m,int n){
    for(int j=1;j<n;j++){
        double key=A[j];
        int i=j-1;
        while(i>=0&&A[i]<key){
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
    }
}

void mg_sort(int A[],int m,int n){
    if(n>m){
        int p=((m+n)/2);
        mg_sort(A,m,p);
        mg_sort(A,p+1,n);
        merge(A,m,p,n);
    }
}

void merge(int A[],int m,int p,int n){
    int n1=0;
    int n2=0;
    n1=p-m+1+1;//"+1"build a space for max
    n2=n-p+1;
    double L[n1];
    double R[n2];
    for(int i=0;i<(n1-1);i++){
        L[i]=A[m+i];
    }
    for(int j=0;j<(n2-1);j++){
        R[j]=A[p+j+1];
    }
    L[n1-1]=LONG_MIN;
    R[n2-1]=LONG_MIN;
    int i=0,j=0;
    for(int k=m;k<=n;k++){
        if(L[i]>R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }
}
void min_heapify(int A[],int i,int n){
    int smallest=i;
    int l=i*2+1;
    int r=i*2+2;
    if(l<n&&A[l]<A[smallest])
        smallest=l;
    if(r<n&&A[r]<A[smallest])
        smallest=r;
    if(smallest!=i){
        swap(A[i],A[smallest]);
        min_heapify(A,smallest,n);
    }
}

void heap_sort(int A[],int n){
    for(int i=n/2-1;i>=0;i--){
        min_heapify(A,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(A[0],A[i]);
        min_heapify(A,0,i);
    }
}

int partition(int A[],int p,int n){
    int pivot=A[n];
    int i=p-1;
    for(int j=p;j<=n-1;j++){
        if(A[j]>pivot){
             i++;
             swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[n]);
    return (i+1);
}

void quick_sort(int A[],int p,int n){
    if(p<n){
        int pi=partition(A,p,n);
        quick_sort(A,p,pi-1);
        quick_sort(A,pi+1,n);
    }
}

 void counting_sort(int A[],int n){
    int *C;
    C=new int [n];

    int x=A[0];

    for (int j=1;j<n;j++){
    if (A[j] > x)
      x=A[j];
    }

    int *D;
    D=new int [x+1];

    for (int i=0;i<=x;i++){
        D[i] = 0;
    }

    for(int j=0;j<n;j++){
        D[A[j]]++;
    }

    for (int i=x-1;i>=0;i--){
        D[i]+=D[i+1];
    }

    for (int i=n-1;i>=0;i--){
    C[D[A[i]]-1] = A[i];
    D[A[i]]--;

  }

    for (int j=0;j<=n;j++){
    A[j] = C[j];
    }

}

int getMax(int A[],int n){
    int max =A[0];
    for (int i=1;i<n;i++)
        if (A[i]>max)
            max=A[i];


    return max;
}

void countSort(int A[],int n,int exp){

    int *C;
    C=new int [n];


    int *D;
    D=new int [10];

    for (int i=0;i<=9;i++){
        D[i] = 0;
    }

    for(int j=0;j<n;j++){
        D[(A[j]/exp)%10]++;
    }

    for (int i=8;i>=0;i--){
        D[i]+=D[i+1];
    }

    for (int i=n-1;i>=0;i--){
    C[D[(A[i]/exp)%10]-1] = A[i];
    D[(A[i]/exp)%10]--;

  }

    for (int j=0;j<=n-1;j++){
    A[j] = C[j];
    }
}

void radixsort(int A[],int n){
    // Find the maximum number to know number of digits
    int M=getMax(A,n);
    // Do counting sort for every digit.
    for (int exp = 1; M / exp > 0; exp *= 10){
        countSort(A, n, exp);
    }
}


void bucketSort(int A[], int n){
    int max=A[0];
    int min=A[0];
    int exp=1;

    for(int i=0;i<n;i++){
        if(A[i]>max){
            max=A[i];
        }
    }

    for(int i=0;i<n;i++){
        if(A[i]<min){
            min=A[i];
        }
    }
	// 1) Create empty buckets
	vector<int> b[10];
	// 2) Put elements in different buckets
	for (int i = 0; i < n; i++) {
        int bi=((float) A[i]/max)*9;
		b[bi].push_back(A[i]);
	}

	// 3) Sort individual buckets
	for (int i = 0; i < 10; i++)
		sort(b[i].begin(), b[i].end(),greater<int>());


	int index=0;
        for (int i = 9; i >=0; i--){
            for (int j = 0; j < b[i].size(); j++){
                A[index] = b[i][j];
                index++;
            }

        }
}

