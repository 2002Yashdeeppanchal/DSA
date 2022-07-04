#include<bits/stdc++.h>
#define nline "\n"
using namespace std;

//implementation of stack using arrays
class Stack{
    //data members
    public:
    int *arr;
    int size;
    int top;

    //constructor
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }  

    void push(int element){
        if((size-top)>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<nline;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflow"<<nline;
        }
    }

    bool isempty(){
        if(top==-1)return true;
        else return false;
    }

    int peek(){
        if(top>=0 and top<size){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<nline;
            return -1;
        }
    }
};


int main(int argc, char const *argv[])
{
    //creation of stack using stl
    //this is a LIFO data structure
    // stack<int>s;
    // s.push(8);
    // s.push(2);
    // s.push(3);
    // s.push(4);

    // s.pop();
    // cout<<s.top()<<nline;
    

    Stack st(5);
    st.push(42);
    st.push(32);
    st.push(12);
    st.push(2);

    cout<<st.peek()<<nline;

    st.pop();
    cout<<st.peek()<<nline;

    return 0;
}
