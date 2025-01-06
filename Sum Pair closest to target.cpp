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
// Initial template for C++

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> sumClosest(vector<int> &arr, int target)
    {
        // code here
        if (arr.size() < 2)
        {
            return {}; // Return an empty vector
        }
        vector<int> ans(2);
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = arr.size() - 1;
        int diff = 0;
        int diffVal = INT_MAX;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
            if (abs(target - sum) < diffVal)
            {
                diffVal = abs(target - sum);
                ans[0] = arr[i];
                ans[1] = arr[j];
            }
            if (sum > target)
            {
                j--;
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                // Exact match found
                break;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty())
        {
            cout << "[]";
        }
        else
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
