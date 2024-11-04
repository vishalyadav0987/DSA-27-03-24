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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }

        // create queue for level traversal
        queue<TreeNode *> q;
        q.push(root);

        // creating flag for level
        // ------> true;
        // false <-------
        bool leftToRight = true;
        int level = 0;
        while (!q.empty())
        {

            // storing level value;
            int n = q.size();
            vector<int> ans(n);

            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                int index = leftToRight ? i : n - i - 1;
                // ans[level][index] = temp->val;
                ans[index] = temp->val;

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            result.push_back(ans);
            level++;
            leftToRight = !leftToRight;
        }
        cout << level;
        return result;
    }
};