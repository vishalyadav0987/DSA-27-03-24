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
    // values of both the BST in a sorted order.
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
    vector<int> mergeSortedArray(vector<int> &in1, vector<int> &in2)
    {
        int n1 = in1.size();
        int n2 = in2.size();
        vector<int> res;
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2)
        {
            if (in1[i] <= in2[j])
            {
                res.push_back(in1[i]);
                i++;
            }
            else
            {
                res.push_back(in2[j]);
                j++;
            }
        }

        while (i < n1)
        {
            res.push_back(in1[i]);
            i++;
        }

        while (j < n2)
        {
            res.push_back(in2[j]);
            j++;
        }

        return res;
    }

    Node *inorderToBst(vector<int> &res, int n, int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }

        int mid = (s + e) / 2;
        Node *root = new Node(res[mid]);
        root->left = inorderToBst(res, n, s, mid - 1);
        root->right = inorderToBst(res, n, mid + 1, e);

        return root;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        // Your code here
        vector<int> in1;
        vector<int> in2;
        // step 1: inoerder of both tree
        inorder(root1, in1);
        inorder(root2, in2);

        // Step 2: Merge two sorted array
        vector<int> res = mergeSortedArray(in1, in2);

        int s = 0;
        int n = res.size();
        int e = n - 1;

        // step 3 : create bst using soreted array;
        //  return inorderToBst(res,n,s,e);

        return res;
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