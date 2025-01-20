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

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data)
{
    Node *new_node = new Node(data);
    if (!head || head->data >= data)
    {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data)
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {
        // code here
        Node *prev1 = NULL;
        Node *prev2 = NULL;
        Node *curr1 = head1;
        Node *curr2 = head2;
        while (curr1 != NULL && curr2 != NULL)
        {
            if (curr1->data > curr2->data)
            {
                prev2 = curr2;
                curr2 = curr2->next;
            }
            else
            {
                prev1 = curr1;
                curr1 = curr1->next;
                if (prev2 != NULL)
                {
                    prev2->next = prev1;
                }
                else
                {
                    head2 = prev1; // Update head2 if this is the first merge
                }
                prev1->next = curr2;
                prev2 = prev1;
            }
        }

        if (curr1 != NULL)
        {
            prev2->next = curr1;
        }
        else if (curr2 != NULL)
        {
            prev2->next = curr2;
        }

        return head2;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int T;
    cin >> T;
    cin.ignore();
    while (T--)
    {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp)
        {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp)
        {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends