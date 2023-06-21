Brute force approach :

 ListNode* middleNode(ListNode* head) {
          ListNode* temp;
          int count=0;
          temp = head;
          while(temp!=NULL){
              count++;
              temp = temp->next;
          }
          int p,q=0;
          if(count%2==0)
            p = (count/2) + 1;

          else
            p = (count+1)/2;

          temp = head;
          while(temp->next!=NULL){
              q++;
              if(q==p)
                  return temp;
              temp = temp->next;
          }
          return temp;
    }


Optimised approach ( Tortoise-hare method)

  ListNode* middleNode(ListNode* head) {
          ListNode *fast,*slow;
          if(head==NULL)
            return NULL;

          fast = head;
          slow = head;

          while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
          }
          return slow;
    }
