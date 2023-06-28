// TC : O(N)
// SC : O(1)


ListNode* oddEvenList(ListNode* head) {
        ListNode *even, *odd, *temp;
        
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }
        odd = head;
        even = head->next;
        temp = even;
        
        while(odd->next!=NULL && even->next!=NULL){

            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;

        }
        odd->next = temp;
        return head;
    }
