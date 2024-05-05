//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int target)
    {
        // Your Code Here
        sort(arr, arr + n);
        int j, k;
        for (int i = 0; i < n - 2; i++)
        {
            j = i + 1;
            k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum ==target)
                {
                    return true;
                }
                else if (sum < target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends