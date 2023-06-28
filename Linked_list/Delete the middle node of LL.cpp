//TC : O(N)
//SC : O(1)

ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp, *prev;
        temp = head;
        int count = 0;
        if(head->next==NULL){
            return NULL;
        }
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        int pos = count/2;
        temp = head;
        int i=0;
        while(i!=pos){
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        return head;
    }
