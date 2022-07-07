//O(N) space le ke to aata hi hai 
//ye beech me ghusane vali approach hai without using any extra space


Node<int>* solve(Node<int>* first,Node<int>* second){
    
    if(first->next==NULL){
        //if only one element is present in the first list then we cant enter the while loop
        //simply add first to second and go
        first->next=second;
        return first;
    }
    
    Node<int>* curr1=first;
    Node<int>* next1=curr1->next;
    Node<int>* curr2=second;
    Node<int>* next2=curr2->next;
    
    while(next1!=NULL and curr2!=NULL){
        if(curr2->data>=curr1->data and curr2->data<=next1->data){
            //add the node between curr1 and next1
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            //update the pointers
            curr1=curr2;
            curr2=next2;
        }
        else{
            //curr1 and next1 ko aage le aao ab
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){//means that first list is empty ab jo bhi list two me ho usko first ke peeche lga do or done 
                curr1->next=curr2;
                return first;
            }
        }
    }
    
    return first;
} 


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL)return second;
    if(second==NULL)return first;
    
    if(first->data<=second->data){
        return solve(first,second);
    }
    else{
        return solve(second,first);
    }
}
