  ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp;
        temp = head;
        int count=0; 
        if(head->next==NULL)
            return NULL;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        ListNode *prev;        
        temp = head;
        int pos = (count-n) + 1;
        int i=1;
        if(pos==1){
            head = head->next;
            return head;
        }
        while(i<pos){
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        return head;
    }
