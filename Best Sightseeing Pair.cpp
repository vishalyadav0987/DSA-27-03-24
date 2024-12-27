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
    int maxScoreSightseeingPair(vector<int> &values)
    {
        // maxi value[i]+1 from left from j.
        // then itatrate from 1 + with value[j]-j
        // use also array for store maxv maxValueFromLeftOfJ
        int maxValueFromLeftOfJ = values[0];
        int ans = 0;
        for (int j = 1; j < values.size(); j++)
        {
            ans = max(ans, (maxValueFromLeftOfJ + (values[j] - j)));
            maxValueFromLeftOfJ = max(maxValueFromLeftOfJ, values[j] + j);
        }
        return ans;
    }
};
int main()
{
    return 0;
}