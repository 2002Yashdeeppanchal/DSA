#include<bits/stdc++.h>

class comparator{
      public:
    bool operator()(Node<int>* a,Node<int>* b){
        return (a->data > b->data);
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &arr)
{
    priority_queue<Node<int>*,vector<Node<int>*>,comparator>p;
    int k=arr.size();
    if(k==0){//if the size of arr is zero
        return nullptr;
    }
    for(int i=0;i<k;i++){//pushing all the first node of all LL
        if(arr[i]!=nullptr)
            p.push(arr[i]);
    }
  //create a new LL with head and tail pointing to nullptr
    Node<int>* head=nullptr;
    Node<int>* tail=nullptr;
    while(!p.empty()){
        Node<int>* temp=p.top();
        p.pop();
        if(head==nullptr and tail==nullptr){//initially when head and tail are both nullptr
            head=temp;
            tail=temp;
            if(temp->next!=nullptr){//temp is the original node of some LL then push its next element into minheap
                p.push(temp->next);
            }
        }
        else{
            tail->next=temp;
            tail=tail->next;
            
            if(temp->next!=nullptr){
                p.push(temp->next);
            }
            
        }
    }
    return head;
}
