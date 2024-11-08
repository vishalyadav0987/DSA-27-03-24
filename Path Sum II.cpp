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
    void solve(TreeNode *root, int targetSum, vector<vector<int>> &result,
               vector<int> ans, int sum)
    {
        if (root == NULL)
        {
            return;
        }

        sum += root->val;
        ans.push_back(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
            {
                result.push_back(ans);
            }
        }

        solve(root->left, targetSum, result, ans, sum);
        solve(root->right, targetSum, result, ans, sum);

        sum -= root->val;
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        vector<int> ans;
        int sum = 0;
        solve(root, targetSum, result, ans, sum);
        return result;
    }
};