//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int arr[], int n)
    {
        // Code here
        vector<int> res;
        int max_right = arr[n - 1];
        res.push_back(max_right);
        //     int count = -1;
        //     int maxi = INT_MIN;
        //     int start = 0;
        //   while(count < n){
        //       for(int i = count + 1; i < n; i++){
        //           if(arr[i] > maxi){
        //               maxi = arr[i];
        //               start = i;
        //           }
        //       }
        //       res.push_back(maxi);
        //       maxi = INT_MIN;
        //       count = start;
        //   }
        //   return res;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= max_right)
            {
                res.push_back(arr[i]);
                max_right = arr[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    long long t;
    cin >> t; // testcases
    while (t--)
    {
        long long n;
        cin >> n; // total size of array

        int a[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(a, n);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends