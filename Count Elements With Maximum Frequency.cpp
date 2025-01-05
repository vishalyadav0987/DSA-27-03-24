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
    int maxFrequencyElements(vector<int> &nums)
    {
        map<int, int> mpp;
        for (auto i : nums)
        {
            mpp[i]++;
        }

        int maxCount = 0;
        for (const auto &pair : mpp)
        {
            maxCount = max(maxCount, pair.second);
        }
        int maxiSum = 0;
        for (auto i : mpp)
        {
            if (i.second == maxCount)
            {
                maxiSum += i.second;
            }
        }
        return maxiSum;
    }
};
int main()
{
    return 0;
}