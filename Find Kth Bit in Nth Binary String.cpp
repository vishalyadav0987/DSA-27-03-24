class Solution
{
public:
    string generate(int n)
    {
        if (n == 1)
        {
            return "0";
        }

        // Recursive call to get the previous series
        string prev_series = generate(n - 1);
        string inverted = "";
        for (char bit : prev_series)
        {
            inverted +=
                (bit == '0') ? '1' : '0'; // Invert '0' to '1' and '1' to '0'
        }

        // Return previous series + "1" + reverse of previous series
        return prev_series + "1" +
               string(inverted.rbegin(), inverted.rend());
    }
    char findKthBit(int n, int k)
    {
        string gerenatedString = generate(n + 1);

        return gerenatedString[k - 1];
    }
};