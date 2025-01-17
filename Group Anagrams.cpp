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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;

        for (auto str : strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            mpp[s].push_back(str);
        }

        for (auto [x, y] : mpp)
        {
            ans.push_back(y);
        }
        return ans;
    }
};
int main()
{
    return 0;
}