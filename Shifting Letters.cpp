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
    string shiftingLetters(string s, vector<int> &shifts)
    {
        long long comulativeSum = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            comulativeSum += shifts[i];
            s[i] = (s[i] - 'a' + comulativeSum) % 26 + 'a';
        }
        return s;
    }
};
int main()
{
    return 0;
}