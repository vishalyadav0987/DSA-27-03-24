//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long x)
    {

        // Your code here
        // lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        // minus from from starting index ans
        // because it will return pointer to the point
        int ans = -1;
        long long low = 0;
        long long high = n - 1;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if (arr[mid] <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends