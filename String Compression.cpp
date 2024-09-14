#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0;
        int ansIndex = 0;
        while (i < chars.size())
        {
            int j = i + 1;
            while (j < chars.size() && chars[i] == chars[j])
            {
                j++;
            }
            // agar match nh hota
            // toh bhara nikal jayenge
            // aur check count 1 se bada
            // ush character array me dal denge

            // store that char
            chars[ansIndex] = chars[i];
            ansIndex++;

            int cnt = j - i;
            if (cnt > 1)
            {
                // converting count in single digit
                string cnt1 = to_string(cnt);
                for (char ch : cnt1)
                {
                    chars[ansIndex] = ch;
                    ansIndex++;
                }
            }
            i = j;
        }
        return ansIndex;
    }
};