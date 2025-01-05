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
    // Function for cyclic increment
    char cyclicIncrement(char ch, int k)
    {
        return 'a' +
               ((ch - 'a' + k) % 26 + 26) % 26;
    }

    // Function for cyclic decrement
    char cyclicDecrement(char ch, int k)
    {
        return 'a' +
               ((ch - 'a' - k) % 26 + 26) % 26;
    }

    // LINE SWEEP ALGORITHUM
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.length();
        vector<int> diff(n + 1, 0);
        for (const auto &shift : shifts)
        {
            int start = shift[0], end = shift[1], direction = shift[2];
            int value = (direction == 1) ? 1 : -1;
            diff[start] += value;
            diff[end + 1] -= value;
        }

        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i)
        {
            cumulativeShift += diff[i];
            if (cumulativeShift > 0)
            {
                s[i] = cyclicIncrement(s[i], cumulativeShift);
            }
            else if (cumulativeShift < 0)
            {
                s[i] = cyclicDecrement(s[i], -cumulativeShift);
            }
        }

        return s;
    }
};
int main()
{
    return 0;
}