#include<bits/stdc++.h>
using namespace std;
#define nline "\n"

class node{

    public:
    int data;
    node* next;

    node(int d){
        this->data=d;
        this->next=NULL;
    }

    ~node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory is free for the node with the data "<<val<<nline;
    }
};


void insertion(node* &tail,int element,int d){
    //if the list is empty
    if(tail==NULL){
        node* temp=new node(d);
        tail=temp;
        temp->next=temp;//pointing to itself
    }
    else{
        //assuming that the element is present in the list
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void deletion(node* &tail,int val){
    if(tail==NULL){
        cout<<"list is empty"<<nline;
        return;
    }
    else{
        //assuming that the val is present in the DLL
        node* prev=tail;
        node* curr=prev->next;
        while(curr->data!=val){
            prev=curr;
            curr=curr->next;
        }
        if(curr==prev){
            //means that there is single element
            tail=NULL;
        }
        if(tail==curr){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void printLL(node* tail){
    if(tail==NULL){
        cout<<"list is empty";
        return;
    }
    node* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
    cout<<nline<<nline;
}

int main(){

    node* tail=NULL;
    insertion(tail,5,4);

    insertion(tail,4,1);
    insertion(tail,1,7);
    insertion(tail,7,3);
    insertion(tail,3,5);

    printLL(tail);

    deletion(tail,7);

    printLL(tail);
    return 0;
}
