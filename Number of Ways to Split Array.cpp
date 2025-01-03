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
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long left = sum;
        long long right = 0;
        int ansCnt = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            right += nums[i];
            left -= nums[i];
            if (left >= right)
                ansCnt++;
        }

        return ansCnt;
    }
};
int main()
{
    return 0;
}