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
    int getLength(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int fromEnd = getLength(head)-k;
        cout<<fromEnd<<endl;
        ListNode* temp = head;
        int cnt=1;
        ListNode* fromBeg = head;
        ListNode* fromLast = head;
        ListNode* prev = NULL;
        while(fromBeg!=NULL && cnt <k){
            prev=fromBeg;
            fromBeg=fromBeg->next;
            cnt++;
        }
        cnt=0;
        while(fromLast!=NULL && cnt < fromEnd){
            fromLast=fromLast->next;
            cnt++;
        }

        int a = fromBeg->val;
        int b = fromLast->val;
        fromBeg->val = b;
        fromLast->val = a;
        return head;

    }
};