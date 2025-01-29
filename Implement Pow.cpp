#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <numeric>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <ctime>
//{ Driver Code Starts

using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    double power(double b, int e)
    {
        // code here
        double ans = 1.0;
        int n = abs(e);
        while (n > 0)
        {
            // if power is odd so
            // 2^21 == 2*2^20
            if (n % 2 == 1)
            {
                ans *= b;
                n--;
            }
            else
            {
                // if power is even
                // 2^20/2 == (2^2)^20/2
                n = n / 2;
                b = b * b;
            }
        }

        if (e < 0)
            return 1.0 / ans;
        else
            return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--)
    {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends