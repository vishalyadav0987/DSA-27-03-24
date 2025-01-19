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
//{ Driver Code Starts
// Initial Template for C++
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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends

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
    int getLength(Node *head)
    {
        int len = 0;
        while (head != NULL)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    void moveForward(Node *&temp, Node *&prev, Node *&secondPart, int &move)
    {
        int cnt = 0;
        while (cnt < move - 1)
        {
            temp = temp->next;
            cnt++;
        }
        prev = temp;
        secondPart = prev->next;
    }
    void secondPardToLast(Node *secondPart, Node *&secondPartLast)
    {
        while (secondPart != NULL)
        {
            secondPartLast = secondPart;
            secondPart = secondPart->next;
        }
    }
    Node *rotate(Node *head, int k)
    {
        // Your code here
        int len = getLength(head);
        if (k == len)
            return head;
        int move;
        if (k > len)
        {
            move = k % len;
        }
        else
        {
            move = k;
        }
        if (move == 0)
            return head;
        Node *temp = head;
        Node *prev = NULL;
        Node *secondPart = NULL;
        moveForward(temp, prev, secondPart, move);
        prev->next = NULL;
        Node *secondPartLast = NULL;
        secondPardToLast(secondPart, secondPartLast);
        secondPartLast->next = head;

        return secondPart;
    }
};

//{ Driver Code Starts.

int main()
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

        // Read numbers from the input line
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Node *head = nullptr;

        // Check if the array is empty
        if (!arr.empty())
        {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i)
            {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends