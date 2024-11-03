class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;
        int n = s.length();

        while (n--)
        {
            if (s == goal)
                return true;
            rotate(s.begin(), s.begin() + 1, s.end());
        }

        return false;
    }
};