//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int KthMissingElement(int a[], int n, int k);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << KthMissingElement(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends

int KthMissingElement(int arr[], int n, int k)
{
    // Complete the function
    int ans = 0;
    bool flag = 0;
    int count = k;
    int diff = 0;
    for (int i = 0; i < n - 1; i++)
    {
        diff = 0;
        if ((arr[i] + 1) != arr[i + 1])
        {
            diff += (arr[i + 1] - arr[i]) - 1;

            if (diff >= count)
            {
                ans = arr[i] + count;
                flag = 1;
                break;
            }
            else
            {
                count -= diff;
            }
        }
    }
    if (flag)
    {
        return ans;
    }
    return -1;
    // return k + high + 1;
}