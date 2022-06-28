bool detectLoop(Node* head)
    {
        //if LL has only one element then slow and fast is pointing to same head so this check is for
        if(head->next==NULL){
            if(head->next!=head)return false;
            else return true;
        }
        Node* fast=head;
        Node* slow=head;
        while(slow!=NULL and fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
