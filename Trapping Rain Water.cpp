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
    int trap(vector<int> &h)
    {
        int n = h.size();
        int left = 0;
        int right = n - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int ans = 0;
        while (left < right)
        {
            if (h[left] >= h[right])
            {
                if (h[right] > maxRight)
                {
                    maxRight = h[right];
                }
                else
                {
                    ans += maxRight - h[right];
                }
                right--;
            }
            else
            {
                if (h[left] > maxLeft)
                {
                    maxLeft = h[left];
                }
                else
                {
                    ans += maxLeft - h[left];
                }
                left++;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}