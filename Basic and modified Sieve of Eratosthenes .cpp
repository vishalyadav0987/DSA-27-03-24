#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPrimes(int n)
    {
        // firstly i mark all prime
        // sieve of erothesises
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        int cnt = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                cnt++;

                // i == 2 so i am itrating 2 to 10 and checking kon kon 2 ki table
                // me aa raha ushe position ko hum false mark karte ja raha hai
                // ans so on
                // n*log(logn)
                for (int j = 2 * i; j < n; j = j + i)
                {
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};