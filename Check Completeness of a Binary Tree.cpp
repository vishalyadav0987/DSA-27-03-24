#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <numeric>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <ctime>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    // for left Child = 2 * i + 1
    // for right Child = 2 * i + 2
    // for 0 base indexing
    bool isCompleteBst(TreeNode *root, int index, int cntNode)
    {
        if (root == NULL)
            return true;
        if (index >= cntNode)
            return false;
        else
        {
            bool left = isCompleteBst(root->left, 2 * index + 1, cntNode);
            bool right = isCompleteBst(root->right, 2 * index + 2, cntNode);
            return (left && right);
        }
    }
    bool isCompleteTree(TreeNode *root)
    {
        int cntNode = countNodes(root);
        int index = 0;
        return isCompleteBst(root, index, cntNode);
    }
};
int main()
{
    return 0;
}