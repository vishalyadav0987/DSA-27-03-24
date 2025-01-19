#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <numeric>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <ctime>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getLength(ListNode *head)
    {
        int len = 0;
        while (head != NULL)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    void moveForward(ListNode *&temp, ListNode *&prev, int move)
    {
        int cnt = 0;
        while (cnt < move)
        {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        int len = getLength(head);

        k = k % len;
        if (k == 0)
            return head;

        int move = len - k;
        ListNode *temp = head;
        ListNode *prev = NULL;

        moveForward(temp, prev, move);

        prev->next = NULL;
        ListNode *secondPart = temp;

        ListNode *secondPartLast = secondPart;
        while (secondPartLast->next != NULL)
        {
            secondPartLast = secondPartLast->next;
        }

        secondPartLast->next = head;

        return secondPart;
    }
};

int main()
{
    return 0;
}