//{ Driver Code Starts
// Initial Template for C++

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
    vector<vector<string>> anagrams(vector<string> &arr)
    {
        // code here
        map<string, vector<string>> mpp;
        vector<vector<string>> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            string sortedStr = arr[i];
            sort(sortedStr.begin(), sortedStr.end());
            mpp[sortedStr].push_back(arr[i]);
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
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

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word)
        {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string>> result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends