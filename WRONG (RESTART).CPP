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

int KthMissingElement(int arr[], int n, int K)
{
    // Complete the function
    // int low = 0;
    // int high = n-1;
    // while(low<=high){
    //     int mid = (low+high)/2;
    //     int missing = arr[mid] - (mid + 1);
    //     if(missing < k){
    //         low=mid+1;
    //     }
    //     else{
    //         high=mid-1;
    //     }
    // }
    // return low + k;
    // // return k + high + 1;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missingUntilMid = arr[mid] - (mid + arr[0]);

        if (missingUntilMid < K)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    int totalMissingUntilHigh = arr[high] - (high + arr[0]);
    int kthMissingElement = arr[high] + (K - totalMissingUntilHigh);

    if (kthMissingElement > arr[n - 1])
    {
        return kthMissingElement;
    }

    return kthMissingElement <= arr[n - 1] ? kthMissingElement : -1;
}