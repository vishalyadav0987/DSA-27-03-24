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
    ListNode* reverse(ListNode* head) {
        string s1 = "";
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
       return prev;
    }
    ListNode* middleLL(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=slow->next;
        while(fast!=NULL && fast->next !=NULL){
            fast = fast->next->next;
            slow=slow->next;
        }

        return slow;
    }
    bool isPalindrome(ListNode* head) {
        
        // step 1 find middle of ll
        ListNode* middle = middleLL(head);

        // step2 revese the ll from middle
        ListNode* temp=middle->next;
        middle->next = reverse(temp);

        // step 3 compare element head == middle  from

        ListNode* head1=head;
        ListNode* head2 = middle->next;
        while(head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        
        }

        return true;

    }
};