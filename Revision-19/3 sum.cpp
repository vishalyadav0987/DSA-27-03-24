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
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                long long sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};
int main()
{
    return 0;
}