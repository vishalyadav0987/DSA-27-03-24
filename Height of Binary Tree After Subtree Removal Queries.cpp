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
    int level[1000001];               // level of all the node
    int height[100001];               // height of all the nodes
    int levelMaxHeight[100001];       // store max of each level
    int levelSecondMaxHeight[100001]; // store 2nd max of each level
    int findHeight(TreeNode *root, int treeLevel)
    {
        if (root == NULL)
        {
            return 0;
        }

        // use dfs
        level[root->val] = treeLevel;
        height[root->val] = max(findHeight(root->left, treeLevel + 1),
                                findHeight(root->right, treeLevel + 1)) +
                            1;
        if (levelMaxHeight[treeLevel] < height[root->val])
        {
            levelSecondMaxHeight[treeLevel] = levelMaxHeight[treeLevel];
            levelMaxHeight[treeLevel] = height[root->val];
        }
        else if (levelSecondMaxHeight[treeLevel] < height[root->val])
        {
            levelSecondMaxHeight[treeLevel] = height[root->val];
        }

        // return height of each level;
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        findHeight(root, 0);

        // LEVEL + HEIGHT - 1;
        vector<int> ans;
        for (int &node : queries)
        {
            // nodd that we have delete
            int L = level[node]; // o(1) node ka level
            // checking jis node ko hum dlete kar rahe ushi max height toh nh
            // ush level agar height toh second max lenge nh wohi shi
            int result = L + (levelMaxHeight[L] == height[node] ? levelSecondMaxHeight[L] : levelMaxHeight[L]) - 1;
            ans.push_back(result);
        }
        return ans;
    }
};