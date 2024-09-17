#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> mp;
        vector<string> ans;
        string word = "";
        for (char ch : s1)
        {
            if (ch == ' ')
            {
                mp[word]++;
                word = "";
            }
            else
            {
                word += ch;
            }
        }
        if (!word.empty())
        {
            mp[word]++;
        }
        word = "";
        for (char ch : s2)
        {
            if (ch == ' ')
            {
                mp[word]++;
                word = "";
            }
            else
            {
                word += ch;
            }
        }

        if (!word.empty())
        {
            mp[word]++;
        }

        for (auto &[st, count] : mp)
        {
            if (count == 1)
            {
                ans.push_back(st);
            }
        }
        return ans;
    }
};