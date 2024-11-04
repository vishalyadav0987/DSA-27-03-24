class Solution
{
public:
    string compressedString(string word)
    {
        string comp = "";
        int i = 0;
        while (i < word.length())
        {
            int j = i;
            while (j < word.length() - 1 && (j - i < 8) &&
                   (word[j] == word[j + 1]))
            {
                j++;
            }
            comp += to_string(j - i + 1) + word[i];
            i = j + 1;
        }
        return comp;
    }
};