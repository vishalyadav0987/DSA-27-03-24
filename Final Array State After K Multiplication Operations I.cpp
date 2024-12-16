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
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

        for (int i = 0; i < nums.size(); i++)
        {
            minH.push({nums[i], i});
        }
        for (int i = 0; i < k; i++)
        {
            pair<int, int> top = minH.top();

            minH.pop();

            nums[top.second] = top.first * multiplier;
            minH.push({top.first * multiplier, top.second});
        }
        return nums;
    }
};
int main()
{
    return 0;
}
int main()
{
    return 0;
}