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
    void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &rootIndex, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
    {
        if (rootIndex >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        // create root;
        int element = postorder[rootIndex++];
        TreeNode *root = new TreeNode(element);
        int position = nodeToIndex[element];

        // recursiveCalls
        root->right = solve(inorder, postorder, rootIndex, position + 1,
                            inorderEnd, n, nodeToIndex);
        root->left = solve(inorder, postorder, rootIndex, inorderStart,
                           position - 1, n, nodeToIndex);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
        reverse(postorder.begin(), postorder.end());
        int postOrderIndex = 0;
        TreeNode *root =
            solve(inorder, postorder, postOrderIndex, 0, n - 1, n, nodeToIndex);
        return root;
    }
};