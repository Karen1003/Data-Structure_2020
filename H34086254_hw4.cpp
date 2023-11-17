/*
   This code can be compiled and run ok.

   This code is to first input a txt file.Second,enqueue and dequeue the number by doubly linked list into the queue.
   Each time you dequeue,the number needs to be converted into its binary form.
   Then store the calculated binary numbers into stack by singly linked lists.Finally.pop those numbers and print out

   usage:
     H34086254_hw4.cpp

   input files:
     number01 number02 number03

   output files:
     number01.txt number02.txt number03.txt

   compile:
     g++ -o H34086254_hw4 H34086254_hw4.cpp

   pseudocode:
     class DListNode{
        private:
            DListNode*next;
            DListNode*prev;
        public:
            int key;
            friend class LinkedList;
     }

     class SListNode{
        private:
            int bin;
            SListNode*prev;
        public:
            initialize
            friend class LinkedList;
     }

     class LinkedList{
        private:
            int bin;
            DListNode *tail;
            SListNode *top;
        public:
            initialize
            DListNode *head;
            void enqueue(int x);
            void dequeue();
            bool queue_empty();
            void trans_binary(int x);
            void push(int data);
            void pop();
            bool stack_empty();
     }

    void LinkedList::enqueue(int x){
        build a newNode
        if queue is empty
           head=tail=newNode;
        else
           tail->next=newNode;
           newNode->prev=tail;
           tail=newNode;
    }

    void LinkedList::dequeue(){
        DListNode *current=head;
        if queue is not empty{
            send number int the head into trans_binary(int x)
            head=head->next;
            delete current;
            if(head!=0){
               head->prev=0;
            }
            if(head==0){
                tail=0;
            }
        }
    }

    bool LinkedList::queue_empty(){
        if queue is empty
            return 1
    }

    void LinkedList::trans_binary(int x){
        while(x>0){
        bin=x%2
        x=x/2
        push bin into stack
        }
        while(stack is empty){
           pop()
        }


    }

    void LinkedList::push(int x){
        build a newNode
        newNode->prev= top;
        top = newNode;
    }

    void LinkedList::pop(){
        SListNode *current = top;
        if (stack is empty){
            cout << "List is empty." << endl;
        }
        else
        {
            cout<<bin;
            top=top->prev;
            delete current;
        }
    }

    bool LinkedList::stack_empty(){
        if stack is empty
            return 1
    }

    int main(){
        input filename
        LinkedList list;
        ifstream fp;
        fp.open(a);
        int x;
        while(fp>>x){
            list.enqueue(x);
        }
         fp.close();
        while(list.queue_empty()==0){
            cout<<list.head->key<<"->";
            list.dequeue();
            cout<<endl;
        }
    }

   coded by CHEN,HONG-YIN, ID: H34086254, email: h34086254@ncku.edu.tw
   date: 2020.11.05
*/
#include<iostream>
#include<fstream>

using namespace std;
class LinkedList;

class DListNode{
    private:

        DListNode*next;
        DListNode*prev;
    public:
        int key;
        DListNode():key(0),next(0),prev(0){};//initialize
        DListNode(int a):key(a),next(0),prev(0){};
        friend class LinkedList;
};

class SListNode{
    private:
        int bin;
        SListNode*prev;
    public:
        SListNode():bin(0),prev(0){};
        SListNode(int a):bin(a),prev(0){};
        friend class LinkedList;
};
class LinkedList{
private:
    int bin;
    DListNode *tail;
    SListNode *top;
public:
    LinkedList():head(0),tail(0),top(0){};//initialize
    DListNode *head;
    void enqueue(int x);
    void dequeue();
    bool queue_empty();
    void trans_binary(int x);
    void push(int data);
    void pop();
    bool stack_empty();
};

void LinkedList::enqueue(int x){

    DListNode *newNode=new DListNode(x);//build a new node which bring x



    if(queue_empty()){
        head=tail=newNode;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        //前後都要連到
        tail=newNode;
    }
}

void LinkedList::dequeue(){
    DListNode *current=head;
    if(queue_empty()==0){
        trans_binary(current->key);

        head=head->next;
        delete current;
        if(head!=0){
           head->prev=0;

        }
        if(head==0){
            tail=0;
        }

    }
}

bool LinkedList::queue_empty(){
    return head == 0;
}

void LinkedList::trans_binary(int x){

    while(x>0){
    bin=x%2;
    x=x/2;
    push(bin);
    }
    while(stack_empty()==0){
       pop();
    }


}

void LinkedList::push(int x){
    SListNode *newNode = new SListNode(x);// 配置新的記憶體
    newNode->prev= top;// 先把first接在newNode後面
    top = newNode;
}

void LinkedList::pop(){
    SListNode *current = top;
    if (stack_empty()){
        cout << "List is empty." << endl;
    }
    else
    {
        cout<<current->bin;
        top=top->prev;
        delete current;

    }
}

bool LinkedList::stack_empty(){
    return top == 0;
}

int main(){
    string a;
    cout<<"input filename"<<endl;
    cin>>a;
    LinkedList list;
    ifstream fp;

    fp.open(a);
    int x;
    while(fp>>x){
        list.enqueue(x);
    }
     fp.close();
   while(list.queue_empty()==0){
    cout<<list.head->key<<"->";
    list.dequeue();

    cout<<endl;
    }
}
