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
// User function template for C++

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &arr)
    {
        // code here
        long long product = 1;
        long long product2 = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            product *= arr[i];
            if (arr[i] != 0)
            {
                product2 *= arr[i];
            }
        }
        vector<int> ans(arr.size());
        int cntZeros = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                cntZeros++;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                if (cntZeros > 1)
                {
                    ans[i] = 0;
                }
                else
                {
                    ans[i] = product2;
                }
            }
            else
            {
                ans[i] = product / arr[i];
            }
        }

        return ans;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends