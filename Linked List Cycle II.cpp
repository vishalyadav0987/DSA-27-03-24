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
    ListNode* FLOYDVERCELALGORITHUM(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != NULL && fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
            }

            slow = slow->next;

            if(slow==fast){
                return slow;
            }

        }
            return NULL;
    }
    ListNode* returnPos(ListNode* head){
        if (head == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* intersectingNode = FLOYDVERCELALGORITHUM(head);
        if(intersectingNode==NULL){
            return NULL;
        }

        while(slow!=intersectingNode){
            slow=slow->next;
            intersectingNode=intersectingNode->next;
        }

        return slow;
    }
    ListNode* detectCycle(ListNode* head) {
        ListNode *ans = returnPos(head);
        return ans;
    }
}; ̰