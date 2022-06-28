Node* kReverse(Node* head, int k) {
    if(head==NULL or head->next==NULL){
        return head;
    }
    //reverse first k nodes
    int cnt=0;
    Node* prev=NULL;
    Node* curr=head;
    Node* forwardnode=head->next;
    while(cnt<k and curr!=NULL){
        forwardnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forwardnode;
        cnt++;
    }
    
    
    //aage ki nodes k ke group me recursion dekh lega
    if(curr!=NULL){
        head->next=kReverse(curr,k);//do a dry run it takes a few minutes but clear this recursion call
    }
    
    return prev;
}
