//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> increment(vector<int> digits, int n)
    {
        // code here
        for (int i = n - 1; i >= 0; i--)
        {
            digits[i]++;
            if (digits[i] != 10)
            {
                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }
        std::vector<int> result = {1};
        result.reserve(digits.size());
        result.insert(result.end(), digits.begin(), digits.end());
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        char c;

        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr, N);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends