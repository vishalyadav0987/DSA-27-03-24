#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans = "";
        int i = 0;
        while (i < s.length())
        {
            if (i > 0 && s[i] == s[i - 1])
            {
                s.erase(i - 1, 2);
                i = 0;
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};