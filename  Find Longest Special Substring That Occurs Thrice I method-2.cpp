class Solution
{
public:
    int maximumLength(string s)
    {
        map<pair<char, int>, int> mpp;

        // generte all possible substring that is specail
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            int len_of_special_str = 0;
            for (int j = i; j < s.length(); j++)
            {
                if (ch == s[j])
                {
                    len_of_special_str++;
                    mpp[{ch, len_of_special_str}]++;
                }
                else
                {
                    break;
                }
            }
        }

        int ans = 0;
        for (auto it : mpp)
        {
            int length = it.first.second;
            int freq = it.second; // freq of substr
            if (freq >= 3 && ans < length)
            {
                ans = length;
            }
        }

        return ans == 0 ? -1 : ans;
    }
};