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
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr)
    {
        // code here
        long long sum = accumulate(arr.begin(), arr.end(), 0LL);
        int n = arr.size();
        long long currSum = 0;
        int i = 1;
        currSum += arr[0];
        while (i < n)
        {
            if (currSum == sum - currSum - arr[i])
            {
                return i;
            }
            currSum += arr[i];
            i++;
        }

        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends