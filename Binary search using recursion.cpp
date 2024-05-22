//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int binaryRecusive(int arr[], int low, int high, int k)
    {
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            binaryRecusive(arr, mid + 1, high, k);
        else
            binaryRecusive(arr, low, mid - 1, k);
    }
    int binarysearch(int arr[], int n, int k)
    {
        // code here
        return binaryRecusive(arr, 0, n - 1, k);
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
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends