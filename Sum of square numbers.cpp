#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c == 1)
            return true;
        long long i = 0;
        long long j = (int)sqrt(c);
        while (i <= j)
        {
            long long num = i * i + j * j;
            if (num == (long)c)
            {
                return true;
            }
            else if (num < (long)c)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};