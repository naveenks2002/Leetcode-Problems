//TC : O(N)
//SC : O(1)

int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *fast,*slow,*temp;
    slow = head;
    fast = head;
    
        while(fast!=NULL && fast->next!=NULL){
            slow  = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                int count=1;
                temp = slow->next;
                while(temp!=slow){
                    count++;
                    temp=temp->next;
                }
                return count;
            }
        }
        return 0;
}
