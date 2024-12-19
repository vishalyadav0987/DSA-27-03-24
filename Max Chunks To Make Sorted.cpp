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
    int maxChunksToSorted(vector<int> &arr)
    {
        int ans = 0;
        int maxVal = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == 0)
            {
                maxVal = arr[i];
            }
            else
            {
                maxVal = max(arr[i], maxVal);
            }
            if (maxVal == i)
            {
                ans++;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}