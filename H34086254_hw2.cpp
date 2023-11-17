/*
   This code can be compiled and run ok.

   This is to generate random algorithm question
   ,and let the users to answer and finally calculate the average correct rate
   usage:
     H34086254_hw2.cpp

   input files:
     no inputfile

   output files:
     no outputfile

   compile:
     g++ -o H34086254_hw2 H34086254_hw2.cpp

   pseudocode:
    input random seed;
    input [l,u];
    t_start = time(NULL);
    int GenRanInt(int l, int u)
    for(int m=0;m<Q.n_questions;m++){
    a=rand() % (u-l+1)+l;
    b=rand() % (u-l+1)+l;
    type=rand()%4;
    Print_Q(m, qu);
    Check_Result(m, qu);
    }
    t_end = time(NULL);
    duration = difftime(t_end, t_start);
    Print_WQA(qu);
    ===================================
    Print_Q(m, qu){
        cout<<"Q["<<m+1<<"]:";
        if(type==1||type==3){
            if(a>b){
                cout<<a<<str<<b;
            }
            else
                cout<<b<<str<<a;
        }
        else
            cout<<a>>str>>b;
    }
    Check_Result(m, qu){
        if(ansc==c)
            return isCorrect=1;
        else
            return isCorrect=0;
    }
    Print_WQA(qu){
        if(isCorrect==0)
            cout<<"Ans= "<<c<<" Not= "<<ansc<<endl;
        double avg_correct_rate=right/n_questions;
        cout<<"Average correct rate = "<<avg_correct_rate*100<<"%"<<endl;
        cout<<"Totally you take "<<duration<<" seconds";
    }
   coded by CHEN,HONG-YIN, ID: H34086254, email: h34086254@ncku.edu.tw
   date: 2020.09.23
*/

#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
struct question{
    int type;
    int a,b,d,c,r,ansc,ansr,n_questions;
    char str;
    double wrong=0.0;
    double right=0.0;
    bool isCorrect;

};
time_t t_start, t_end; //變數宣告
double duration; //記錄時間長度
int GenRanInt(int l, int u);

void Print_Q(int m, question *Q);

bool Check_Result(int m, question *Q);

void Print_WQA(question *Q);

int main(){
    struct question Q;
    question* qu;

    cout<<"#questions?"<<endl;
    cin>>Q.n_questions;
    qu=new question[Q.n_questions];
    qu->n_questions=Q.n_questions;
    int seed=0;
    cout << "input random seed (0 to use time as seed) = ";
    cin>>seed;

    int l,u;
    cout<<"input [l, u] = ?";
    cin>>l>>u;

    t_start = time(NULL);

    if(seed==0){
        GenRanInt(l,u);
        srand((unsigned)(time(NULL))) ;

    }
    else{
        GenRanInt(l,u);
        srand(seed);
    }
    for(int m=0;m<Q.n_questions;m++){
    qu[m].a=rand() % (u-l+1)+l;
    qu[m].b=rand() % (u-l+1)+l;

    char str;
    qu[m].type=rand()%4;
    switch(qu[m].type){
        case 0:
        qu[m].str='+';
        break;

        case 1:
        qu[m].str='-';
        break;

        case 2:
        qu[m].str='*';
        break;

        case 3:
        qu[m].str='/';
        break;
    }
    if(qu[m].type==0||qu[m].type==1){
        qu[m].a=rand() % (u-l+1)+l;
        qu[m].b=rand() % (u-l+1)+l;
    }
    else{
        qu[m].a=rand() % (u-l+1)+l;
        qu[m].b=rand() % 10+l;
    }
        Print_Q(m, qu);
        Check_Result(m, qu);
    }
    t_end = time(NULL);
    duration = difftime(t_end, t_start);
    Print_WQA(qu);
}

int GenRanInt(int l, int u){
    return rand() % (u-l+1)+l;
}

void Print_Q(int m, question *Q){
    cout<<"Q["<<m+1<<"]:";
    if((Q+m)->type==1||(Q+m)->type==3){
        if((Q+m)->a>(Q+m)->b){
            cout<< (Q+m)->a << (Q+m)->str<< (Q+m)->b <<"=?";
        }
        else{
            cout<< (Q+m)->b << (Q+m)->str<< (Q+m)->a <<"=?";
        }
    }
    else
    cout<< (Q+m)->a << (Q+m)->str<< (Q+m)->b <<"=?";
}

bool Check_Result(int m, question *Q){
    if((Q+m)->type==0){
        (Q+m)->c = (Q+m)->a + (Q+m)->b;
    }

    if((Q+m)->type==1){
        if((Q+m)->a>(Q+m)->b){
            (Q+m)->c = (Q+m)->a - (Q+m)->b;
        }
        else
        (Q+m)->c = (Q+m)->b - (Q+m)->a;
    }

    if((Q+m)->type==2){
        (Q+m)->c = (Q+m)->a * (Q+m)->b;
    }

    if((Q+m)->type==3){
        if((Q+m)->a>(Q+m)->b){
            (Q+m)->c =(Q+m)->a /(Q+m)->b;
            (Q+m)->r = (Q+m)->a % (Q+m)->b;
        }
        else{
           (Q+m)->c = (Q+m)->b / (Q+m)->a;
            (Q+m)->r = (Q+m)->b % (Q+m)->a;
        }
    }

    if((Q+m)->type!=3){
        cin>>(Q+m)->ansc;
        if((Q+m)->ansc==(Q+m)->c){
            cout<<"Bingo !! Very good !!"<<endl;
            Q->right++;
            return (Q+m)->isCorrect=1;
        }
        else{
            cout<<"!! Wrong !! Answer = "<<(Q+m)->c<<endl;
            Q->wrong++;
            return (Q+m)->isCorrect=0;
        }
    }
    else{
        cin>> (Q+m)->ansc >> (Q+m)->ansr;
        if((Q+m)->ansc==(Q+m)->c && (Q+m)->ansr==(Q+m)->r){
            cout<<"Bingo !! Very good !!"<<endl;
            Q->right++;
            return (Q+m)->isCorrect=1;
        }
        else{
           cout<<"!! Wrong !! Answer = "<<(Q+m)->c<<" "<<(Q+m)->r<<endl;
           Q->wrong++;
           return (Q+m)->isCorrect=0;
        }
    }

}

void Print_WQA(question *Q){
    cout<<"Among the "<<Q->n_questions<<" questions,you give "<< Q->wrong <<" wrong answer"<<endl;
    for(int n=0;n<Q->n_questions;n++){
       if((Q+n)->isCorrect==0){
        if((Q+n)->type!=3){
            cout<<"Q["<<n+1<<"]:";
            cout<< (Q+n)->a << (Q+n)->str<< (Q+n)->b <<"=?";
            cout<<"Ans= "<<(Q+n)->c<<" Not= "<<(Q+n)->ansc<<endl;
        }
        else{
            cout<<"Q["<<n+1<<"]:";
            cout<< (Q+n)->a << (Q+n)->str<< (Q+n)->b <<"=?";
            cout<<"Ans= "<<(Q+n)->c<<" "<<(Q+n)->r<<" Not= "<<(Q+n)->ansc<<" "<<(Q+n)->ansr<<endl;
        }
    }
    }
    double avg_correct_rate=Q->right/Q->n_questions;
    if(avg_correct_rate>0&&avg_correct_rate<=0.3){
        cout<<"Average correct rate = "<<avg_correct_rate*100<<"%"<<endl;
        cout<<"Hey! You are worse than an elementary school student!"<<endl;
    }
    if(avg_correct_rate>0.3&&avg_correct_rate<=0.6){
        cout<<"Average correct rate = "<<avg_correct_rate*100<<"%"<<endl;
        cout<<"Too bad! You require more practice in arithmetics!"<<endl;
    }
    if(avg_correct_rate>0.6&&avg_correct_rate<=0.9){
        cout<<"Average correct rate = "<<avg_correct_rate*100<<"%"<<endl;
        cout<<"You can do some arithmetic operations, but should be more cautious."<<endl;
    }
    if(avg_correct_rate>0.9&&avg_correct_rate<=1){
       cout<<"Average correct rate = "<<avg_correct_rate*100<<"%"<<endl;
       cout<<"Well done! I am very impressed by your performance!"<<endl;
       }
    cout<<"Totally you take "<<duration<<" seconds";
}


