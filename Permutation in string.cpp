#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkEqual(int a[26], int b[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        // traverse s1 store count
        int count1[26] = {0};
        for (int i = 0; i < s1.length(); i++)
        {
            int index = s1[i] - 'a'; // a - a = 0 index pe ++ kardo
            count1[index]++;
        }
        // travers s2 string store count
        int count2[26] = {0};
        int i = 0;
        int windowSize = s1.length();
        if (s2.length() < windowSize)
            return false;
        for (i = 0; i < windowSize; i++)
        {
            int index = s2[i] - 'a';
            count2[index]++;
        }
        if (checkEqual(count1, count2))
        {
            return true;
        }
        while (i < s2.length())
        {
            char newChar = s2[i];
            int index = newChar - 'a'; // a - a = 0 index pe ++ kardo
            count2[index]++;

            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            count2[index]--;

            i++;

            if (checkEqual(count1, count2))
            {
                return true;
            }
        }
        return false;
    }
};