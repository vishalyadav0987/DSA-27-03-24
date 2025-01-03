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
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> rangeArr(words.size());
        vector<int> ans;
        int i = 0;
        int k = 0;
        string vowStr = "aeiou";
        for (auto w : words)
        {
            char ch1 = w[0];
            char ch2 = w[w.length() - 1];
            if ((find(vowStr.begin(), vowStr.end(), ch1) != vowStr.end()) && (find(vowStr.begin(), vowStr.end(), ch2) != vowStr.end()))
            {
                rangeArr[k++] = ++i;
            }
            else
            {
                rangeArr[k++] = i;
            }
        }

        for (auto q : queries)
        {
            int l = q[0];
            int r = q[1];
            l = l == 0 ? 0 : rangeArr[l - 1];
            ans.push_back(rangeArr[r] - l);
        }

        return ans;
    }
};
int main()
{
    return 0;
}