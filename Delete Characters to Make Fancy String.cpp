class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans = "";
        ans += s[0];
        char prev = s[0];
        int cnt = 1;
        for (int i = 1; i < s.length(); i++)
        {
            if (prev != s[i])
            {
                cnt = 1;
                prev = s[i];
                ans += s[i];
            }
            else if (prev == s[i])
            {
                cnt++;
                if (cnt < 3)
                {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};