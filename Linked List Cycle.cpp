/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int fcd(ListNode *head){
        if(head==NULL){
            return 0;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
            if(slow==fast && slow != NULL){
                return 1;
            }

        }
            return 0;
    }
    bool hasCycle(ListNode *head) {
        if(fcd(head)) return true;
        else return false;
    }
};