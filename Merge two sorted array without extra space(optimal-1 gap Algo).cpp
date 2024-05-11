//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void swapIfGreater(long long arr1[], long long arr2[], int index1, int index2)
    {
        if (arr1[index1] > arr2[index2])
        {
            swap(arr1[index1], arr2[index2]);
        }
    }

public:
    // Function to merge the arrays.
    //  tc = log(n+m) * o(n+m)
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        // code here
        // gap algorithum
        int len = n + m;
        int gap = (len / 2) + (len % 2);
        // 9/2 = 4.5 + 1 = 5.5 but i have taken int so it 5 looklike ciel function
        // if (len % 2)  odd give 1
        while (gap > 0)
        {
            int i = 0;
            int j = i + gap;
            while (j < len)
            {
                // if compare arr1 and arr2
                if (i < n && j >= n)
                {
                    swapIfGreater(arr1, arr2, i, j - n); // j = 5 [5 - 4] = 1 is a index of second array
                }
                // if compare arr2 and arr2
                else if (i >= n)
                {
                    swapIfGreater(arr2, arr2, i - n, j - n);
                }
                // arr 1 and arr1
                else
                {
                    swapIfGreater(arr1, arr1, i, j);
                }
                i++;
                j++;
            }
            if (gap == 1)
                break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        long long arr1[n], arr2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);

        for (int i = 0; i < n; i++)
            cout << arr1[i] << " ";

        for (int i = 0; i < m; i++)
            cout << arr2[i] << " ";

        cout << endl;
    }

    return 0;
}

// } Driver Code Ends