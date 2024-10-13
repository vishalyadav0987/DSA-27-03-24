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
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }

        ListNode* newNode = new ListNode(-1);
        ListNode* temp = newNode;

        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != NULL) {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        newNode = newNode->next;
        return newNode;
    }
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = slow->next;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        // Merge sort

        // base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // step 1: Find middle to split right ad left half;
        ListNode* mid = findMiddle(head);

        // 1->2->3->4->5->x
        // l = 1->2->3->x
        // r = 4->5->x

        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        // step 2: recursivelly call to sort both halfs
        left = sortList(left);
        right = sortList(right);

        // step 3: Merge both left and right half to compare them
        ListNode* result = merge(left, right);

        // step 5: return ans
        return result;
    }
};