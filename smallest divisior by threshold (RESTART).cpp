//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int sumOfDivision(vector<int> &arr, int divisior)
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += ceil((double)arr[i] / (double)divisior);
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int K)
    {

        // Write your code here.
        int low = 1;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(nums[i], maxi);
        }
        int high = maxi;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (sumOfDivision(nums, mid) <= K)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1; // agr bada hoga toh sum > k se
            }
        }
        return low;
    }
};

//{ Driver Code Starts.
int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends