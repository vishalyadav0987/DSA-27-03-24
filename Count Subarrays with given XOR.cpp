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
    long subarrayXor(vector<int> &arr, int k)
    {
        // code here
        unordered_map<int, int> mpp;
        int cnt = 0;
        mpp[0] = 1;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum ^= arr[i];
            int check = sum ^ k;
            cnt += mpp[check];
            mpp[sum]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0)
    {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num)
        {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends