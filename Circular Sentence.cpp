class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        int n = sentence.length();

        if (sentence[n - 1] != sentence[0])
            return false;

        for (int i = 0; i < n; i++)
        {
            if (sentence[i] == ' ')
            {
                if (sentence[i + 1] != sentence[i - 1])
                    return false;
            }
        }

        return true;
    }
};