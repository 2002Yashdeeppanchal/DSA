Node* fldloopdetection(Node* head){
        if(head==NULL){
            return head;
        }
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL and slow!=NULL){
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
    
    Node* startingnodeofloop(Node* head){
        Node* slow=head;
        Node* ptr=fldloopdetection(head);
        while(slow!=ptr){
            slow=slow->next;
            ptr=ptr->next;
        }
        return slow;
    }
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node* isloop=fldloopdetection(head);
        if(isloop!=NULL){
            Node* start=startingnodeofloop(head);
            Node* temp=start;
            while(temp->next!=start){
                temp=temp->next;
            }
            temp->next=NULL;
        }
        
    }
