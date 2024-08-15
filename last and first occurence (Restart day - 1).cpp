//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long LowerBound(vector<long long> arr, long long x)
    {
        long long low = 0;
        long long ans = -1;
        long long high = arr.size() - 1;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if (arr[mid] == x)
            {
                ans = mid;
                low = mid + 1;
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

public:
    long long upperBound(vector<long long> arr, long long x)
    {
        long long low = 0;
        long long ans = -1;
        long long high = arr.size() - 1;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if (arr[mid] == x)
            {
                ans = mid;
                high = mid - 1;
            }
            else if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    pair<long, long> indexes(vector<long long> v, long long x)
    {
        // code here
        long long a = LowerBound(v, x);
        long long b = upperBound(v, x);

        return make_pair(b, a);
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        vector<long long> v;
        cin >> n;
        for (long long i = 0; i < n; i++)
        {
            cin >> k;
            v.push_back(k);
        }
        long long x;
        cin >> x;
        Solution obj;
        pair<long, long> pair = obj.indexes(v, x);

        if (pair.first == pair.second and pair.first == -1)
            cout << -1 << endl;
        else
            cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}

// } Driver Code Ends