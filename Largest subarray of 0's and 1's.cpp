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
    int maxLen(vector<int> &arr)
    {
        // Your code here

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                arr[i] = -1;
            }
        }

        // [1,-1,1,1,1,-1,-1]
        unordered_map<int, int> mpp;
        int maxLength = 0;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                maxLength = i + 1;
            }
            else
            {
                if (mpp.find(sum) != mpp.end())
                {
                    maxLength = max(maxLength, i - mpp[sum]);
                }
                else
                {
                    mpp[sum] = i;
                }
            }
        }

        return maxLength;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--)
    {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num)
        {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends