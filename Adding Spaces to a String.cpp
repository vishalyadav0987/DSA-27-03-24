class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string ans = "";
        int i = 0;
        int j = 0;
        int sp = spaces[j];
        while (i < s.length())
        {
            if (i != sp)
            {
                ans += s[i];
            }
            else
            {
                ans += " ";
                ans += s[i];
                j++;
                if (j < spaces.size())
                {
                    sp = spaces[j];
                }
            }
            i++;
        }

        return ans;
    }
};