//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int noOfDays(int arr[], int n, int cap)
    {
        int load = 0;
        int day = 1;
        for (int i = 0; i < n; i++)
        {
            if (load + arr[i] > cap)
            {
                day += 1;
                load = arr[i];
            }
            else
            {
                load += arr[i];
            }
        }
        return day;
    }
    int leastWeightCapacity(int arr[], int n, int d)
    {
        // code here
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxi = max(arr[i], maxi);
        }
        int low = maxi;
        int high = 0;
        for (int i = 0; i < n; i++)
        {
            high += arr[i];
        }
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (noOfDays(arr, n, mid) <= d)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends