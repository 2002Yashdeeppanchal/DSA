#include<bits/stdc++.h>
using namespace std;
#define nline "\n"

class node{
    public:
    int data;
    node* prev;
    node* next;

    //constructor
    node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }


    //destructor
    ~node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory is free for the node with data "<<val<<nline;
    }
};

void printLL(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<nline<<nline;
}

int getlen(node* &head){
    int cnt=0;
    node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

void insertathead(node* &head,node* &tail,int d){
    if(head==NULL){//if the list is initially empty
        node* temp=new node(d);
        head=temp;
        tail=temp;
        return;
    }
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insertattail(node* &tail,node* &head,int d){
    if(tail==NULL){//if the list is initially empty
        node* temp=new node(d);
        tail=temp;
        head=temp;
        return;
    }
    node* temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insertatposition(int position,node* &head,node* &tail,int d){
    node* temp=new node(d);
    if(position==1){
        insertathead(head,tail,d);
        return;
    }
    node* curr=head;
    node* back=NULL;
    int cnt=position-1;
    while(cnt){
        back=curr;
        curr=curr->next;
        cnt--;
    }
    if(back->next==NULL){
        insertattail(tail,head,d);
        return;
    }
    temp->next=curr;
    temp->prev=back;
    curr->prev=temp;
    back->next=temp;

}


void deletionofnode(node* &head,node* &tail,int position){
    if(position==1){
        node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* curr=head;
        int cnt=1;
        while(cnt<position){
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            curr->prev->next=NULL;
            tail=curr->prev;
            curr->prev=NULL;
            delete curr;
        }
        else{
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
            curr->next=NULL;
            curr->prev=NULL;
            delete curr;
        }
    }
}

int main(){

    node* node1=new node(8);
    node* head=node1;
    node* tail=node1;
    // cout<<getlen(head);

    insertathead(head,tail,11);
    insertathead(head,tail,2);
    insertathead(head,tail,4);

    insertattail(tail,head,3);
    insertattail(tail,head,1115);


    insertatposition(7,head,tail,66);
    printLL(head);


    deletionofnode(head,tail,4);
    printLL(head);

    return 0;
}
