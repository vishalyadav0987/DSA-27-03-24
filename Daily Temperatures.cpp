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
    vector<int> dailyTemperatures(vector<int> &t)
    {
        stack<int> s;
        int n = t.size();
        vector<int> ans(n);
        ans[n - 1] = 0;
        s.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            while (!s.empty() && t[s.top()] <= t[i])
            {
                s.pop();
            }
            if (!s.empty() && t[s.top()] > t[i])
            {
                ans[i] = s.top() - i;
            }
            s.push(i);
        }

        return ans;
    }
};
int main()
{
    return 0;
}