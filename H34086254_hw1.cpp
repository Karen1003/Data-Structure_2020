/*
   This code can be compiled and run ok.

   This is to input several integers and find the min,2nd_min,max,2nd_max, sum and product
   usage:
     H34086254_hw1.cpp

   input file:
     no inputfile

   output files:
     no outputfile

   compile:
     g++ -o H34086254_hw1 H34086254_hw1.cpp

   pseudocode:
   cin>>n;
   ------
   insertion sort
   if(n>4)
   cin>>array[n]
   for (int i = 1; i < n; i++) {
        int tmp = array[i];
        int j = i - 1;
        while (tmp < array[j] && j >= 0) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = tmp;
    }
   ------
   int sum=0;
    int product=1;
    for(int i=0;i<n;i++){
        sum+=array[i];
        product*=array[i];
    }
   ------
   else
    input again

   coded by CHEN,HONG-YIN, ID: H34086254, email: h34086254@ncku.edu.tw
   date: 2020.09.13
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"please enter nonnegative integer number n that is larger than 4"<<endl;
    while(true){
    cin>>n;
    int * array;
    array=new int[n];
    if(n>4){
        cout<<"input these "<<n<<" integers";
        for(int i=0;i<n;i++){
            cin>>array[i];
        }

        cout<<"Among the "<<n<<" integers:";
        for(int i=0;i<n;i++)
            cout<<array[i]<<",";
            cout<<endl;


        for (int i = 1; i < n; i++) {
        int tmp = array[i];
        int j = i - 1;
        while (tmp < array[j] && j >= 0) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = tmp;
    }


        cout<<"min="<<array[0]<<endl;

        int a=1;
        while(true){
            if(array[a]!=array[0]){
                cout<<"2nd_min="<<array[a]<<endl;
                break;
            }
            else
                a++;

        }

        cout<<"max="<<array[n-1]<<endl;

        int b=n-2;
        while(true){
            if(array[b]!=array[n-1]){
                cout<<"2nd_max="<<array[b]<<endl;
                break;
            }
            else
                b--;
        }

       int sum=0;
        int product=1;
        for(int i=0;i<n;i++){
            sum+=array[i];
            product*=array[i];
        }
        cout<<"sum="<<sum<<endl;
        cout<<"product="<<product<<endl;
        delete array;
        break;

    }

    else
        cout<<"!!Warning!!" <<endl;
        cout<<n<<"is NOT larger than 4!Please input a positive integer n at least 5"<<endl;

    }

}
