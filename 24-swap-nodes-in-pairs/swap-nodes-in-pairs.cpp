/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        
        ListNode *temp,*ptr,*new_temp,*new_head;
        new_head = head->next;
        temp = head->next;
        ptr = head;

        ListNode *dummy_head = new ListNode(0);
        dummy_head->next =  head;
        while(dummy_head->next!=NULL && temp!=NULL){
            new_temp = temp->next;
            temp->next = ptr;
            ptr->next = new_temp;

            dummy_head->next = temp;
            dummy_head = ptr;

            if(ptr->next!=NULL){
                ptr = ptr->next;
                temp = ptr->next;
            }
        }
        return new_head;
    }
};