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
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node *root)
{
    map<Node *, int> link;
    Node *temp = root;
    for (int i = 0; temp != NULL; i++)
    {
        link[temp] = i;
        temp = temp->next;
    }
    temp = root;
    cout << "[";
    while (temp->next != NULL)
    {
        if (!temp->random)
        {
            cout << "[" << temp->data << ", "
                 << "NULL"
                 << "], ";
        }
        else
            cout << "[" << temp->data << ", " << link[temp->random] + 1 << "], ";
        temp = temp->next;
    }
    if (!temp->random)
    {
        cout << "[" << temp->data << ", "
             << "NULL"
             << "]]\n";
    }
    else
        cout << "[" << temp->data << ", " << link[temp->random] + 1 << "]]\n";
}

bool validation(Node *res, map<Node *, int> &orgAddress)
{
    Node *temp = res;
    for (int i = 0; temp != NULL; i++)
    {
        if (orgAddress.find(temp) != orgAddress.end())
        {
            return false;
        }
        if (orgAddress.find(temp->random) != orgAddress.end())
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

Node *buildLinkedList(vector<pair<int, int>> &v, map<Node *, int> &orgAddress)
{
    vector<Node *> address(v.size());
    Node *head = new Node(v[0].first);
    address[0] = head;
    Node *temp = head;
    orgAddress[head] = 0;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newNode = new Node(v[i].first);
        orgAddress[newNode] = i;
        address[i] = newNode;
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second != -1)
        {
            temp->random = address[v[i].second - 1];
        }
        temp = temp->next;
    }

    return head;
}

bool validateInput(map<Node *, int> &orgAddress, Node *head, vector<pair<int, int>> &v)
{
    vector<Node *> address(v.size());
    Node *temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        if (orgAddress.find(temp) == orgAddress.end() || orgAddress[temp] != i)
        {
            return false;
        }
        address[i] = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        return false;
    }
    temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        int value = v[i].first;
        int randomIndex = v[i].second;

        if (randomIndex == -1)
        {
            if (temp->random != NULL)
            {
                return false;
            }
        }
        else
        {
            Node *tempNode = address[randomIndex - 1];
            if (temp->random != tempNode)
            {
                return false;
            }
        }
        temp = temp->next;
    }
    return true;
}

// } Driver Code Ends
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution
{
public:
    Node *cloneLinkedList(Node *head)
    {
        // Write your code here
        if (head == NULL)
            return head;

        /*
         1. input list ki node ke beach jis node pe khade
            uski copy bane ke ussi ke next me add kar do
            aur newNode ke next ko jis ki copy bnayi uske next
            ke equal kar do
        */

        Node *temp = head;
        while (temp != NULL)
        {
            Node *newNode = new Node(temp->data);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        /*
        Analogy

        1->3 -> random pointer
        2->1
        3->2


        temp ----------->     1->2->3->4->x
                              l  l  l  l    -> next pointers
        head2 = temp->next    1->2->3->4->x


        temp->random (1->3)
        head2->random (1->3) = temp->random->next (1->3->3)

        */

        /*
        2. input list randon pointer ko dekhan fir
            outputlist ka pointer wahi laga dena hai
            we kown that we inset copy same list inBetwwen

        */

        temp = head;
        Node *head2 = temp->next;
        while (temp != NULL)
        {
            if (temp->random == NULL)
            {
                temp->next->random = NULL;
            }
            else
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        /*
        3. Remove all the link that have connect to inset
           newNode in it
        */

        temp = head;
        while (temp != NULL)
        {
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            if (temp2->next != NULL)
                temp2->next = temp2->next->next;
            temp = temp->next;
        }

        return head2;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n); // node data, random node number
        for (int i = 0; i < n; i++)
        {
            int x;
            string y;
            cin >> x >> y;
            if (y == "NULL" || y == "N" || y == "null" || y == "n" || y == "Null")
            {
                v[i] = {x, -1};
            }
            else
            {
                v[i] = {x, stoi(y)};
            }
        }
        map<Node *, int> orgAddress;
        Node *head = buildLinkedList(v, orgAddress);

        Solution ob;
        Node *res = ob.cloneLinkedList(head);
        // check if input modified.
        if (validateInput(orgAddress, head, v))
        {
            if (validation(res, orgAddress))
            {
                print(res);
            }
            else
            {
                cout << "Pointing to the original list\n";
            }
        }
        else
        {
            cout << "Input list modified\n";
        }
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends