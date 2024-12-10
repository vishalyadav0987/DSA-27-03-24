class Solution
{
public:
    int maximumLength(string s)
    {
        unordered_map<string, int> mpp;

        // generte all possible substring that is specail
        for (int i = 0; i < s.length(); i++)
        {
            string str = "";
            for (int j = i; j < s.length(); j++)
            {
                if (str.empty() || str.back() == s[j])
                {
                    str.push_back(s[j]);
                    mpp[str]++;
                }
                else
                {
                    break;
                }
            }
        }

        int ans = 0;
        for (auto [str, cnt] : mpp)
        {
            if (cnt >= 3 && ans < str.length())
            {
                ans = str.length();
            }
        }

        return ans == 0 ? -1 : ans;
    }
};