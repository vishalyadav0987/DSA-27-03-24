#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        while (s.find(part) < s.length())
        {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};