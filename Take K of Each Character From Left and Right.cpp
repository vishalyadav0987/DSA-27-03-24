class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        int aCnt = 0, bCnt = 0, cCnt = 0;
        for (auto ch : s)
        {
            if (ch == 'a')
            {
                aCnt++;
            }
            else if (ch == 'b')
            {
                bCnt++;
            }
            else
            {
                cCnt++;
            }
        }
        int n = s.length();

        if (aCnt < k || bCnt < k || cCnt < k)
            return -1;
        int ans = 0; // non deleted window
        int left = 0;
        int right = 0;
        while (right < s.length())
        {
            if (s[right] == 'a')
                aCnt--;
            else if (s[right] == 'b')
                bCnt--;
            else if (s[right] == 'c')
                cCnt--;

            // deletion count of any character less than then bring back using
            // shrink window
            while (left <= right && (aCnt < k || bCnt < k || cCnt < k))
            {
                if (s[left] == 'a')
                    aCnt++;
                else if (s[left] == 'b')
                    bCnt++;
                else if (s[left] == 'c')
                    cCnt++;
                left++;
            }
            ans = max(ans, (right - left + 1));
            right++;
        }

        return n - ans;
    }
};