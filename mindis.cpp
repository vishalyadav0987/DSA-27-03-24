//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minDist(int arr[], int n, int x, int y)
    {
        // code here
        int mindis = INT_MAX;
        int previousIndex = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x || arr[i] == y)
            {
                if (previousIndex != -1 && arr[i] != arr[previousIndex])
                {
                    mindis = min(mindis, i - previousIndex);
                }
                previousIndex = i;
            }
        }

        if (mindis > n)
            return -1;
        else
            return mindis;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends