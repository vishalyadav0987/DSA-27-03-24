class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int i = 0;
        int j = 0;
        bool ans = false;
        while (i < str1.length() && j < str2.length())
        {
            ans = false;
            char h = str1[i] == 'z' ? 'a' : str1[i] + 1;
            if (str1[i] == str2[j] || h == str2[j])
            {
                ans = true;
                j++;
            }
            i++;
        }

        cout << j;

        if (j != str2.length())
            ans = false;

        return ans;
    }
};