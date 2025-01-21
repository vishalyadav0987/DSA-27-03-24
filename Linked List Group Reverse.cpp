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
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
public:
    Node *reverseList(Node *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *curr = head;
        Node *prev = NULL;
        Node *forward = NULL; // taki node kho na jaye
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }
    int getCount(Node *head)
    {
        int cntNode = 0;
        while (head != NULL)
        {
            cntNode++;
            head = head->next;
        }
        return cntNode;
    }
    void CountAndDivide(Node *head, Node *&temp1, Node *&temp2, int k)
    {
        temp1 = head;
        int cnt = 1;
        while (cnt < k)
        {
            head = head->next;
            cnt++;
        }
        temp2 = head->next;
        head->next = NULL;
    }
    Node *reverseKGroup(Node *head, int k)
    {
        // code here
        // int cntNode = getCount(head);
        // if(cntNode <= k){
        //     return reverseList(head);
        // }
        // Node* temp1 = NULL;
        // Node* temp2 = NULL;
        // CountAndDivide(head,temp1,temp2,k);

        // Node* h1 = reverseList(temp1);
        // Node* h2 = reverseList(temp2);

        // Node* temp = h1;
        // while(temp->next != NULL){
        //     temp = temp->next;
        // }
        // temp->next = h2;
        // return h1;

        if (!head || k <= 1)
            return head;

        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        int count = 0;

        // Reverse the first k nodes
        while (current && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        // If there are nodes remaining, recursively reverse the next group
        if (next)
        {
            head->next = reverseKGroup(next, k);
        }

        // Return the new head of the reversed group
        return prev;
    }
};

//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void)
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        if (arr.empty())
        {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node *head = new Node(data);
        Node *tail = head;
        for (int i = 1; i < arr.size(); ++i)
        {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends