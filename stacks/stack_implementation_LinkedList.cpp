#include<bits/stdc++.h>
#define nline "\n"
using namespace std;


class node{
    public:
    int data;
    node*next;

    //constructor
    node(int data){
        this->data=data;//this means class ke main data member ka pointer
        this->next=NULL;
    }


    //destructor
    ~node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for the data "<<value<<nline;
    }

};

void insertattail(node* &tail,node* &head,int d){
    if(tail==NULL){//if the list is initially empty
        node* temp=new node(d);
        tail=temp;
        head=temp;
        return;
    }
    //create a new node with data d
    node* temp=new node(d);
    tail->next=temp;
    tail=temp;
}


//stack implementation using LinkedList
class Stack{
    public:
    node* tail;
    node* head;

    Stack(){
        tail=NULL;
        head=NULL;
    }

    void push(int d){
        insertattail(tail,head,d);
    }

    int pop(){
        if(tail!=NULL){
            node* prev=head;
            while(prev->next!=tail){
                prev=prev->next;
            }
            delete(tail);
            prev->next=NULL;
            tail=prev;
            return tail->data;
        }
        else{
            return -1;
        }
    }

    int top(){
        if(tail!=NULL){
            return tail->data;
        }
        else{
            cout<<"stack is khali"<<nline;
            return -1;
        }
    }

    bool isempty(){
        if(tail==NULL)return true;
        else{
            return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    
    Stack st;
    st.push(8);
    st.push(1);
    st.push(3);
    st.push(5);
    st.push(7);

    cout<<st.top()<<nline;

    st.pop();

    cout<<st.top()<<nline;

    return 0;
}
