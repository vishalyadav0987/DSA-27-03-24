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
    int countPairs(vector<int> &arr, int target)
    {
        // Your code here
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = arr.size() - 1;
        int cnt = 0;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (sum >= target)
            {
                j--;
            }
            else if (sum < target)
            {
                cnt += j - i;
                i++;
            }
        }

        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends