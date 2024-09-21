#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        if (n == 9)
        {
            for (int i = 1; i <= 9; i++)
            {
                ans.push_back(i);
            }
        }
        int num = 1;
        for (int i = 1; i <= n; i++)
        {
            ans.push_back(num);
            if (num * 10 <= n)
            {
                num *= 10;
            }
            else
            {
                while ((num % 10) == 9 || num == n)
                {
                    num /= 10;
                }
                num++;
            }
        }
        return ans;
    }
};