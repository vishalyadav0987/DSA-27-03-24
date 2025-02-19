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
    vector<int> twoSum(vector<int> &arr, int target)
    {
        // Hash problem
        unordered_map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            int rem = target - arr[i];
            if (mpp.find(rem) != mpp.end())
            {
                ans.push_back(i);
                ans.push_back(mpp[rem]);
            }
            mpp[arr[i]] = i;
        }

        return ans;
    }
};
int main()
{
    return 0;
}