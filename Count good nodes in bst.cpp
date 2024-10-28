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
    void countGreater(TreeNode *root, int prev, int &cnt)
    {
        if (root == NULL)
        {
            return;
        }
        // If the current node's value is greater than or equal to the max value on the path, count it
        if (prev <= root->val)
        {
            cnt++;
            prev = root->val; // if then update prev value
        }

        countGreater(root->left, prev, cnt);
        countGreater(root->right, prev, cnt);
    }
    int goodNodes(TreeNode *root)
    {
        int cnt = 0;
        countGreater(root, root->val, cnt);
        return cnt;
    }
};