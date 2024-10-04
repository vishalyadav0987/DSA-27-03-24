#include <bits/stdc++.h>
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
class Solution
{
public:
    int getLength(ListNode *&head)
    {
        ListNode *temp = head;
        int length = 0;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *prev = NULL;
        ListNode *fast = head->next;
        int len = getLength(head);
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        while (fast->next != NULL)
        {
            fast = fast->next;
            if (fast->next != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        return len % 2 == 0 ? slow->next : slow;
    }
};