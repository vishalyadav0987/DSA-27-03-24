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
    bool isSubset(vector<int> &freq2, vector<int> &freq)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] < freq2[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> ans;

        vector<int> freq2(26, 0);
        for (auto word : words2)
        {
            vector<int> freq(26, 0);
            for (char c : word)
            {
                freq[c - 'a']++;

                freq2[c - 'a'] = max(freq2[c - 'a'], freq[c - 'a']);
            }
        }

        for (auto word : words1)
        {
            vector<int> freq(26, 0);
            for (char c : word)
            {
                freq[c - 'a']++;
            }

            if (isSubset(freq2, freq))
            {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
int main()
{
    return 0;
}