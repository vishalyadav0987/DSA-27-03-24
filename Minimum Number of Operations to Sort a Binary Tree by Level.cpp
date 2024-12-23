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

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        vector<pair<int, int>> v;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int swaps = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i].second == i)
                continue;
            else
            {
                swaps++;
                swap(v[i], v[v[i].second]);
                i--;
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode *root)
    {
        queue<TreeNode *> q;
        int ansCnt = 0;

        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                temp.push_back(front->val);
                q.pop();
                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
            ansCnt += minSwaps(temp);
        }

        return ansCnt;
    }
};
int main()
{
    return 0;
}