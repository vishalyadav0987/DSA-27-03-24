/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    pair<int, int> diameterFast(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            // diameter , height
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        // pair of dimater and height from left
        pair<int, int> left = diameterFast(root->left);
        // pair of dimater and height from right
        pair<int, int> right = diameterFast(root->right);

        // yah toh left me ho sakta dia
        int op1 = left.first;
        // yah toh left me ho sakta dia
        int op2 = right.first;
        // yah fir right + left both height milake -1 karnge because dono root
        // involve in both height
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max({op1, op2, op3});
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        // diameter in first;
        return diameterFast(root).first - 1;
    }
};