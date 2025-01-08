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
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int ansCnt = 0;

        for (int i = 0; i < words.size(); i++)
        {
            string w1 = words[i];
            for (int j = i + 1; j < words.size(); j++)
            {
                string w2 = words[j];

                if (w1.length() > w2.length())
                {
                    continue;
                }
                string prefixCheck = w2.substr(0, w1.length());
                string suffixCheck = w2.substr(w2.length() - w1.length());

                if (prefixCheck == w1 && suffixCheck == w1)
                {
                    ansCnt++;
                }
            }
        }
        return ansCnt;
    }
};
int main()
{
    return 0;
}