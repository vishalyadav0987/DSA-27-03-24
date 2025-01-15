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
    string longestCommonPrefix(vector<string> &strs)
    {
        // tc:o(l*n)
        // l:lenght of word
        // n:lenght of array
        // sc:o(1)
        string ans = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            bool match = true;
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j].length() < i || strs[0][i] != strs[j][i])
                {
                    match = false;
                    break;
                }
            }

            if (!match)
            {
                break;
            }
            else
            {
                ans += strs[0][i];
            }
        }

        return ans;
    }
};
int main()
{
    return 0;
}