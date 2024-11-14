/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex,
                       int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &rootIndex,
                    int inorderStartIndex, int inOrderEnd, int n,
                    map<int, int> &nodeToIndex)
    {
        if (rootIndex >= n || inorderStartIndex > inOrderEnd)
        {
            return NULL;
        }

        // create root node for tree
        int element = preorder[rootIndex++]; // element from pre array
        TreeNode *root = new TreeNode(element);
        // then find same element in inorder array for which element is in
        // right or left side
        int position = nodeToIndex[element];

        // recursiveCalls
        root->left = solve(preorder, inorder, rootIndex, inorderStartIndex,
                           position - 1, n, nodeToIndex);
        root->right = solve(preorder, inorder, rootIndex, position + 1,
                            inOrderEnd, n, nodeToIndex);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // inorder = LNR  LEFT ROOT RIGHT
        // preorder = NLR ROOT LEFT RIGHT
        int preOrderIndex = 0;
        int n = inorder.size();
        map<int, int> nodeToIndex;
        // create mapping of every value with there index
        createMapping(inorder, nodeToIndex, n);
        TreeNode *root =
            solve(preorder, inorder, preOrderIndex, 0, n - 1, n, nodeToIndex);
        return root;
    }
};