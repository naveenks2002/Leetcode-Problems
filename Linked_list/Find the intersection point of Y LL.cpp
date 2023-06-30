/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// TC : O(N)
//SC : O(1)
class Solution {
public:
    int length(ListNode *head){
        int count = 0;
        ListNode *temp;
        temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          if(!headA || !headB) return NULL;
        int lenA = length(headA);
        int lenB = length(headB);

        if(lenA>lenB){
            while(lenA>lenB){
                headA = headA->next;
                lenA--;
            }
        }

        else if(lenA<lenB){
            while(lenA<lenB){
                headB = headB->next;
                lenB--;
            }
        }

        while(headA!=NULL && headB!=NULL){
            if(headA==headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }    
        return NULL;
    }
};
