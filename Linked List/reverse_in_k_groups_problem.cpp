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


//follow up me ho skta hai ki agr LL ka size na k ka multiple ni hai to last window me kuch nodes rh jaengi to unko reverse ni krna
//Leetcode pr yhi problem hai bs last me jo nodes bch gyi unko reverse ni krna to issi code me changes hai thode se lallu se





class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        
        //reverse first k nodes
        int cnt=0;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* ford=curr->next;
        while(cnt<k and curr!=NULL){
            ford=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ford;
            cnt++;
        }
        
        //jb last window me agr kuch nodes rh jae to unko vaps se reverse kr do or head return kro prev to reversed ka head hai apn original hi de rhe hai
        if(cnt!=k){
            curr=prev;
            prev=NULL;
            ford=curr->next;
            while(curr!=NULL){
                ford=curr->next;
                curr->next=prev;
                prev=curr;
                curr=ford;
            }
            return head;
        }
        
        //baki ka recursion kr laega
        if(curr!=NULL){
            head->next=reverseKGroup(curr,k);
        }
        
        //now head prev
        return prev;
    }
};
