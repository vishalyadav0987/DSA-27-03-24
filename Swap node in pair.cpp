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
        if (head == NULL || head->next == NULL) {
            return head; 
        }
        ListNode* newHead = head->next; // when i swap toh head 2 pe phuch
        // jeayega slie phle hi update kar liya
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while (curr && curr->next) {
            next = curr->next;
            curr->next = next->next;
            next->next = curr;
            if (prev != NULL) {
                prev->next = next;
            }
            prev = curr;
            curr = curr->next;
        }
        return newHead;
    }
};