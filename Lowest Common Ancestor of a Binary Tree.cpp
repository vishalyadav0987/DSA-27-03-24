/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }

        // hun phle ush root ko dundenge fir answer return karenge
        if (root->val == p->val || root->val == q->val)
        {
            return root;
        }

        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        // agar left me node miltit aur right se node toh root return kar denge
        if (leftAns != NULL && rightAns != NULL)
        {
            return root;
        }
        else if (leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }
        else if (leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }
        else
        {
            return NULL;
        }
    }
};