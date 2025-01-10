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

class Solution
{
public:
    vector<int> countDistinct(vector<int> &arr, int k)
    {
        // code here.
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i = 0; i < k; i++)
        {
            mpp[arr[i]]++;
        }
        ans.push_back(mpp.size());
        int i = 0;
        int j = k;
        while (j < arr.size())
        {
            mpp[arr[i]]--;
            if (mpp[arr[i]] == 0)
            {
                mpp.erase(arr[i]);
            }
            mpp[arr[j]]++;
            ans.push_back(mpp.size());
            i++;
            j++;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends