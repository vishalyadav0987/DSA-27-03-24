//{ Driver Code Starts
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
#include<numeric>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<iomanip>
#include<ctime>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
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
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int countNodes(Node* tree){
        if(tree==NULL) return 0;
        int cnt = 1 + countNodes(tree->left) + countNodes(tree->right);
        return cnt;
    }
    // for left Child = 2 * i + 1 
    // for right Child = 2 * i + 2
    // for 0 base indexing
    bool isCompleteBst(Node* tree,int index,int cntNode){
        if(tree == NULL) return true;
        if(index >= cntNode) return false;
        else{
            bool left = isCompleteBst(tree->left,2*index+1,cntNode);
            bool right = isCompleteBst(tree->right,2*index+2,cntNode);
            return (left && right);
        }
    }
    // checking maxHeap or not
    // every chid smaller than parent in maxheap
    // we know if any tree is complete bst so it filed from left side
    // if there is 2 case
    // case 1: if complete bst so parent may or may not right child
    // case 2 : right child and left child == null also satisfied maxheap
    bool isMaxHeap(Node* tree){
        if(tree->right == NULL && tree->left == NULL) return true;
        if(tree->right == NULL) return (tree->left->data < tree->data);
        else{
            bool left = isMaxHeap(tree->left);
            bool right = isMaxHeap(tree->right);
            return (left && right && 
            (tree->data > tree->left->data && 
            tree->data > tree->right->data));
        }
        
    }
    
    bool isHeap(struct Node* tree) {
        // code here
        int cntNode = countNodes(tree);
        int index = 0;
        return (isCompleteBst(tree,index,cntNode) && isMaxHeap(tree));
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends