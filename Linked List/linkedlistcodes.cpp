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

void insertathead(node* &head,node* &tail,int d){
    if(head==NULL){//if the list is initially empty
        node* temp=new node(d);
        head=temp;
        tail=temp;
        return;
    }
    //create a new node with data d
    node* temp=new node(d);
    temp->next=head;//new node(temp) ka next is pointing to head now so temp's next = head
    head=temp;// now head is new node
}

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


void insertatposition(node* &head,node* &tail,int position,int d){
    node* temp=head;
    if(position==1){
        insertathead(head,tail,d);
        return;
    }
    //first we reach position-1 th node for which we have to traverse position-2 times
    int cnt=position-2;
    while(cnt){
        temp=temp->next;
        cnt--;
    }
    //what if we insert at last(tail)
    if(temp->next==NULL){
        insertattail(tail,head,d);
        return;
    }
    //then we create a new node with data d
    node* nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}

void deletenode(int position,node* &head,node* &tail){
    if(position==1){
        //deleting head position
        node* temp=head;
        head=head->next;//shifting head to 2nd position
        temp->next=NULL;//as it is still pointing to 2nd node
        delete temp;
    }
    else{
        //deleting any other pos other than head
        node* curr=head;
        node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){//as we are deleting the last node so the tail node is also changing
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void printLL(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<nline<<nline;
}

bool iscyclepresent(node* &head){
    if(head==NULL){
        return false;
    }
    node* temp=head;
    map<node*,bool>visited;
    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}



node* flyodloopdetection(node* &head){
    if(head==NULL){
        return NULL;
    }
    node* slow=head;
    node* fast=head;
    while(slow!=NULL and fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

node* startingnodeofloop(node* &head){
    if(head==NULL)return NULL;

    node* slow=head;
    node* intersection=flyodloopdetection(head);

    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}


void removeloopinLL(node* &head){
    node* startkhasehailoop=startingnodeofloop(head);
    node* temp=startkhasehailoop;
    while(temp->next!=startkhasehailoop){
        temp=temp->next;
    }
    temp->next=NULL;
}


long long int number1(node* l1,long long int* ten,long long int ans){
    if(l1->next==NULL){
        return l1->data;
    }
    ans=number1(l1->next,ten,ans);
    (*ten)*=10;
    ans=ans+((*ten)*(l1->data));
    return ans;
    
}

int main(){
    // // node*nd=new node();
    // (*nd).data=9;
    // cout<<(*nd).data<<nline;
    // cout<<nd->data<<nline;//as nd is the pointer pointing to a node

    //now we can create node by passing the data when we call
    node* node1=new node(1);
    node* head=node1;//create a head node
    
    //for inserting at tail we create a tail node also
    node* tail=node1;

    // printLL(node1);

    // insertathead(head,12);//now head is 12
    // printLL(head);//12 10

    // insertathead(head,15);
    // printLL(head);//15 12 10


    insertattail(tail,head,3);
    insertattail(tail,head,5);

    // printLL(head);//10 13 16

    insertatposition(head,tail,3,8);//10 13 22 16

    insertattail(tail,head,2);
    insertattail(tail,head,1);
    insertattail(tail,head,7);
    insertattail(tail,head,2);
    insertattail(tail,head,9);

    // deletenode(4,head,tail);
    // printLL(head);

    // printLL(head);


    // cout<<head->data<<" "<<tail->data<<nline;


    // for checking the iscyclepresent in LL we are pointing the tail node to 13 node
    // tail->next=head->next;
    // cout<< iscyclepresent(head);//tc=O(n) sc=O(n)
    // cout<< flyodloopdetection(head);//tc=O(n) sc=O(1)
    // cout<<startingnodeofloop(head)->data;
    // removeloopinLL(head);
    // cout<< iscyclepresent(head);
    //must do problem for revising loop detect and remove it using flyod's algo
    // https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=1





    //problems
    //remove duplicates from an unsorted LL
    //phle O(n^2)sol
    /*
    node* curr=head;
    // cout<<curr->data;
    while(curr!=NULL){
        node* temp=curr->next;
        node* prev=curr;
        while(temp!=NULL){
            if(temp->data==curr->data){
                // cout<<temp->data<<" "<<prev->data<<nline;
                node* aagevala=temp->next;
                node* todelete=temp;
                prev->next=aagevala;
                temp=temp->next;
                todelete->next=NULL;
                delete todelete;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        curr=curr->next;
    }

    printLL(head);
    */

    //map ka sol
    // map<int,bool>m;
    // node* temp=head;
    // node* prev=head;
    // while(temp!=NULL){
    //     if(m[temp->data]==true){
    //         node* todelete=temp;
    //         prev->next=temp->next;
    //         temp=temp->next;
    //         todelete->next=NULL;
    //         delete todelete;
    //     }
    //     else{
    //         m[temp->data]=true;
    //         prev=temp;
    //         temp=temp->next;
    //     }
    // }


    


    printLL(head);

    // long long int ten=1;
    // long long int * p=&ten;
    // cout<<number1(head,p,0);

    //reverse a LL
    // node* curr=head;
    // node* prev=NULL;
    // node* ford=curr->next;
    // while(curr!=NULL){
    //     ford=curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=ford;
    // }
    // head=prev;


    printLL(head);

    return 0;
}
