//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order

    void inorder(Node *root, vector<int> &in)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }

    // step 1: convert  bst to soted DLL
    void convertIntoDLL(Node *root, Node *&head, Node *&prev)
    {
        if (root == NULL)
        {
            return;
        }
        // Traverse left subtree
        convertIntoDLL(root->left, head, prev);

        // Process current node
        if (prev == NULL)
        {
            head = root; // First node becomes head
        }
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        // Traverse right subtree
        convertIntoDLL(root->right, head, prev);
    }

    // step 2: Merge 2 sorted linked list
    Node *mergeSoretedLL(Node *head1, Node *head2)
    {
        Node *head = NULL;
        Node *tail = NULL;

        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data <= head2->data)
            {
                if (head == NULL)
                {
                    head = head1;
                    tail = head1;
                    head1 = head1->right;
                }
                else
                {
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                    head1 = head1->right;
                }
            }
            else
            {
                if (head == NULL)
                {
                    head = head2;
                    tail = head2;
                    head2 = head2->right;
                }
                else
                {
                    tail->right = head2;
                    head1->left = tail;
                    tail = head2;
                    head2 = head2->right;
                }
            }
        }

        while (head1 != NULL)
        {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }

        while (head2 != NULL)
        {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }

        return head;
    }

    // step 3; DLL TO singly LL
    void convertDLLToSLL(Node *&head)
    {
        Node *curr = head;

        while (curr != NULL)
        {

            // head have not prev
            Node *nextNode = curr->right;

            curr->right = nextNode;

            curr->left = NULL;

            curr = nextNode;
        }
    }

    // step 4: soted LL to BST
    Node *singlyLLToBst(Node *&head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        if (head->right == NULL)
        {
            return new Node(head->data);
        }

        // find root node soretd ll
        // means center of LL
        Node *slow = head;
        Node *fast = head;
        Node *slow_prev = NULL; // because we break ll from slow prev

        while (fast != NULL && fast->right != NULL)
        {
            slow_prev = slow;
            slow = slow->right;
            fast = fast->right->right;
        }

        // at the end slow on center or root of merge bst
        Node *mergeRoot = new Node(slow->data);

        // firstly we detached tree from slow pointer
        slow_prev->right = NULL;

        mergeRoot->left = singlyLLToBst(head);

        mergeRoot->right = singlyLLToBst(slow->right);

        return mergeRoot;
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        // Your code here
        Node *prev1 = NULL;
        Node *head1 = NULL;
        convertIntoDLL(root1, head1, prev1);

        Node *prev2 = NULL;
        Node *head2 = NULL;
        convertIntoDLL(root2, head2, prev2);

        Node *head = mergeSoretedLL(head1, head2);

        convertDLLToSLL(head);

        Node *mergeRoot = singlyLLToBst(head);

        vector<int> ans;
        inorder(mergeRoot, ans);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends