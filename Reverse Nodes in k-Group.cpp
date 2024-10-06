#include <iostream>
using namespace std;

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        if (head == NULL) {
            return NULL;
        }

        // Check if there are at least k nodes to reverse
        ListNode* check = head;
        for (int i = 0; i < k; ++i) {
            if (check == NULL)
                return head;
            check = check->next;
        }

        // step 1
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        int cnt = 0;
        while (curr != NULL && cnt < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        // step 2
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        // step 3
        return prev;
    }
};