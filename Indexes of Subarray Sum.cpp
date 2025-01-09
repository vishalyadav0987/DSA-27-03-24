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

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        // code here
        int i = 0;
        vector<int> ans;
        int n = arr.size();
        long long sum = 0;
        int j = 0;
        while (j < n)
        {
            sum += arr[j];

            while (sum > target && i < j)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == target)
            {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
            j++;
        }

        if (ans.empty())
        {
            ans.push_back(-1);
            return ans;
        }
        else
        {
            return ans;
        }
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
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result)
        {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends