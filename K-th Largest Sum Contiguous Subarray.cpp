//{ Driver Code Starts
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
// User function Template for C++

class Solution
{
public:
    int kthLargest(vector<int> &arr, int k)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>> minH;
        for (int i = 0; i < arr.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum += arr[j];
                if (minH.size() < k)
                {
                    minH.push(sum);
                }
                else
                {
                    if (sum > minH.top())
                    {
                        minH.pop();
                        minH.push(sum);
                    }
                }
            }
        }

        return minH.top();
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
        int k = stoi(ks);
        Solution obj;
        int res = obj.kthLargest(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends