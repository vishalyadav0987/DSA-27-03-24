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
    void solve(TreeNode *root, int ts, vector<int> pathSumArr, int &pathSumCnt)
    {
        if (root == NULL)
            return;

        // firstly push root in vec
        pathSumArr.push_back(root->val);

        // going toward left
        solve(root->left, ts, pathSumArr, pathSumCnt);
        // going toward right
        solve(root->right, ts, pathSumArr, pathSumCnt);

        // calculate sum of array
        long long sum = 0;
        for (int i = pathSumArr.size() - 1; i >= 0; i--)
        {
            sum += pathSumArr[i];
            if (sum == ts)
            {
                pathSumCnt++;
            }
        }

        // when going upwoard pop elememt from vec
        pathSumArr.pop_back();
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        vector<int> pathSumArr;
        int pathSumCnt = 0;
        solve(root, targetSum, pathSumArr, pathSumCnt);
        return pathSumCnt;
    }
};