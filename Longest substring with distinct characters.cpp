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
// Initial Template for C++
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {
        // code here
        vector<int> freq(26, 0);
        int n = s.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < n)
        {
            freq[s[j] - 'a']++;
            while (freq[s[j] - 'a'] > 1)
            {
                freq[s[i] - 'a']--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends