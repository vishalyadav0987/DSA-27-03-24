//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &array1, vector<int> &array2);

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    double MedianOfArrays(vector<int> &arr1, vector<int> &arr2)
    {
        // Your code goes here
        int n1 = arr1.size();
        int n2 = arr2.size();
        // I want sorter array will be arr1;
        if (n1 > n2)
            return MedianOfArrays(arr2, arr1);
        int low = 0;
        int high = n1; // mininmum no fo iteration here becuase arr1 is always sorter
        // left me kitne element aa sakte hai
        int left = (n1 + n2 + 1) / 2; // 10
        int n = n1 + n2;
        while (low <= high)
        {
            int mid1 = (low + high) / 2; // 5
            int mid2 = left - mid1;      // 10-5 == 5 ele
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = arr1[mid1];
            if (mid2 < n2)
                r2 = arr2[mid2];
            if (mid1 - 1 >= 0)
                l1 = arr1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = arr2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 1)
                {
                    return max(l1, l2);
                }
                else
                {
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            else if (l1 > l2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array2[i];
        }
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}

// } Driver Code Ends