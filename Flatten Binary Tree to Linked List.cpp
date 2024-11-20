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
    void flatten(TreeNode *root)
    {
        // 1. find predecer -> check left hai going to  1 left then right
        // jab tak null na jaye jaise hi null hojaye wohi predecer hoga
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left)
            {
                TreeNode *predecer = curr->left;
                while (predecer->right)
                {
                    predecer = predecer->right;
                }
                predecer->right = curr->right;
                curr->right = curr->left;
            }
            curr = curr->right;
        }
        // left part null
        curr = root;
        while (curr != NULL)
        {
            curr->left = NULL;
            curr = curr->right;
        }
    }
};