//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {

        // your code here
        // we know that if presentElm wohi hogo jiski ocureence n/2 ho hogi iska matlab woh conacel nh hoga
        // yani aur isi elem se uska cnt cancel nh hoga
        // Moore's Voting Algorithm
        int cnt = 0;
        int presentElm;
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                cnt = 1;
                presentElm = arr[i];
            }
            else if (arr[i] == presentElm)
            {
                cnt++;
            }
            else if (arr[i] != presentElm)
            {
                cnt--;
            }
        }
        int cnt1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == presentElm)
            {
                cnt1++;
            }
        }
        if (cnt1 > n / 2)
        {
            return presentElm;
        }
        return -1;
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
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends