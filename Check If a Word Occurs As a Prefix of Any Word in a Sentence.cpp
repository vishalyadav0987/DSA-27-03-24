class Solution
{
public:
    bool check(int i, string sentence, string sw)
    {
        bool ans = true;
        for (int j = 1; j < sw.length(); j++)
        {
            if (sw[j] != sentence[j + i])
            {
                ans = false;
            }
        }
        return ans;
    }
    int isPrefixOfWord(string sentence, string sw)
    {
        int i = 0;
        int wordCnt = 0;
        while (i < sentence.length())
        {
            if (i == 0 || sentence[i - 1] == ' ')
            {
                wordCnt++;
                if (sentence[i] == sw[0])
                {
                    bool val = check(i, sentence, sw);
                    if (val)
                    {
                        return wordCnt;
                    }
                }
            }
            i++;
        }
        return -1;
    }
};