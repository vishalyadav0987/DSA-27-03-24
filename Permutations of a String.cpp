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
class Solution
{
public:
    void solve(string s, int index, vector<string> &ans)
    {
        if (index == s.size())
        {
            ans.push_back(s);
            return;
        }

        for (int j = index; j < s.size(); j++)
        {
            if (j != index && s[j] == s[index])
                continue;
            swap(s[index], s[j]);
            solve(s, index + 1, ans);
            // swap(nums[index], nums[j]);
        }
    }
    vector<string> findPermutation(string &s)
    {
        // Code here there
        sort(s.begin(), s.end());
        vector<string> ans;
        int index = 0;
        solve(s, index, ans);
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
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends