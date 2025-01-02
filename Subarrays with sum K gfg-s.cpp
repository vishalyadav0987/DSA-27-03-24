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
// User function Template for C++

class Solution
{
public:
    int countSubarrays(vector<int> &arr, int k)
    {
        // code here
        int sum = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        // sum = 0;
        // cnt = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            // check k minus sum is present or not
            int lookingFor = sum - k;
            cnt += mpp[lookingFor];
            // if not there
            mpp[sum]++;
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

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends