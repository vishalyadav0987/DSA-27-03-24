class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long i = x;
        long long ans = x;
        // ans.push_back(x);
        // i = (i + 1) | x; // direct jump to next number
        while (n >= 1 && i < LONG_MAX)
        {
            if ((x & (i)) == x)
            {
                ans = i;
                n--;
            }
            i = (i + 1) | x;
        }
        return ans;
    }
};