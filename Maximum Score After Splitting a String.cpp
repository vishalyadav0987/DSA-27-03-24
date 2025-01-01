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
    int maxScore(string s)
    {
        int n = s.length();
        int ans = INT_MIN;
        int totalOnes = count(s.begin(), s.end(), '1');

        int zeroCnt = 0;
        int onesCnt = 0;
        for (int i = 0; i <= n - 2; i++)
        {
            if (s[i] == '1')
                onesCnt++;
            else
                zeroCnt++;

            int rightTotalOnesCnt = totalOnes - onesCnt;
            ans = max(ans, (rightTotalOnesCnt + zeroCnt));
        }

        return ans;
    }
};
int main()
{
    return 0;
}