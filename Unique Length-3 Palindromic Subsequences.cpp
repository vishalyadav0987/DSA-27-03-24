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
    int countPalindromicSubsequence(string s)
    {
        int n = s.length();
        unordered_set<char> letters(s.begin(), s.end());
        int ans = 0;
        // find 1st and last occurence of all char present in set
        for (auto l : letters)
        {

            int first_idx = -1;
            int last_idx = -1;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == l)
                {
                    if (first_idx == -1)
                    {
                        first_idx = i;
                    }
                    last_idx = i;
                }
            }

            // in between checking how many unquie char utne hi palindrome banaege
            unordered_set<char> st;
            for (int j = first_idx + 1; j <= last_idx - 1; j++)
            {
                st.insert(s[j]);
            }

            ans += st.size();
        }

        return ans;
    }
};
int main()
{
    return 0;
}