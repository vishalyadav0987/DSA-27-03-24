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
    int countPairs(vector<int> &arr, int target)
    {
        // Complete the function
        int n = arr.size();
        int ansCnt = 0;
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            int sum = arr[i] + arr[j];
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
                int se = arr[i];
                int ende = arr[j];
                int scnt1 = 0;
                int ecnt2 = 0;
                while (i <= j && se == arr[i])
                {
                    i++;
                    scnt1++;
                }
                while (i <= j && ende == arr[j])
                {
                    j--;
                    ecnt2++;
                }
                if (se == ende)
                {
                    ansCnt += (scnt1 * (scnt1 - 1)) / 2;
                }
                else
                {
                    ansCnt += scnt1 * ecnt2;
                }
            }
        }
        return ansCnt;
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends