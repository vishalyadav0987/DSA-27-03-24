//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    // code here
    sort(arr, arr + n);
    int ans = -1;
    int ans2 = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        { // floor
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    int low1 = 0;
    int high1 = n - 1;
    while (low1 <= high1)
    {
        int mid = (low1 + high1) / 2;
        if (arr[mid] >= x)
        { // floor
            ans2 = mid;
            high1 = mid - 1;
        }
        else
        {
            low1 = mid + 1;
        }
    }
    ans = ans == -1 ? -1 : arr[ans];
    ans2 = ans2 == -1 ? -1 : arr[ans2];
    return make_pair(ans, ans2);
}