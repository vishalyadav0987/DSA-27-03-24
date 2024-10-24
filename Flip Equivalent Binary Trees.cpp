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
    bool comparison(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return true;
        if (!root1 || !root2 || root1->val != root2->val)
            return false;

        bool check = (comparison(root1->left, root2->left) || comparison(root1->left, root2->right)) && (comparison(root1->right, root2->right) || comparison(root1->right, root2->left));
        return check;
    }
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        return comparison(root1, root2);
    }
};
