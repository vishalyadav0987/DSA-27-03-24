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
    int countGoodStrings(int low, int high, int zero, int one)
    {
        const int MOD = 1e9 + 7;
        vector<int> ways(high + 1, 0);
        ways[0] = 1;

        for (int length = 0; length <= high; ++length)
        {
            if (ways[length] == 0)
                continue;
            if (length + zero <= high)
            {
                ways[length + zero] = (ways[length + zero] + ways[length]) % MOD;
            }
            if (length + one <= high)
            {
                ways[length + one] = (ways[length + one] + ways[length]) % MOD;
            }
        }

        int count = 0;
        for (int i = low; i <= high; ++i)
        {
            count = (count + ways[i]) % MOD;
        }

        return count;
    }
};
int main()
{
    return 0;
}