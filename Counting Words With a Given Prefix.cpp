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
    int prefixCount(vector<string> &words, string pref)
    {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string s1 = pref;
            string s2 = words[i];
            string prefixCheck = s2.substr(0, s1.length());
            if (prefixCheck == s1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    return 0;
}