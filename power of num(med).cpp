//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // You need to complete this fucntion

    long long power(int N, int R)
    {
        // Your code here
        if (N == 0)
            return 0;
        //   long long po = 1;
        //   for(long long i = 0; i < R; i++){
        //       po *= N;
        //       po %= 1000000007;
        //   }
        //   return po;
        long long base = N;
        long long res = 1;
        while (R > 0)
        {
            if (R % 2 == 1)
            {
                res = (res * base) % 1000000007;
            }
            base = (base * base) % 1000000007;
            R /= 2;
        }
        return res;
    }
};

//{ Driver Code Starts.

// compute reverse of a number
long long rev(long long n)
{
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}

int main()
{
    int T;
    cin >> T; // testcases

    while (T--)
    {
        long long N;
        cin >> N; // input N

        long long R = 0;

        // reverse the given number n
        R = rev(N);
        Solution ob;
        // power of the number to it's reverse
        long long ans = ob.power(N, R);
        cout << ans << endl;
    }
}
// } Driver Code Ends