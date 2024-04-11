//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        // Your code here
        // return vector with correct order of elements
        vector<int> arr;
        int i = 0, j = 0;
        int prev;
        if (arr1[i] > arr2[j])
        {
            prev = arr2[j];
            arr.push_back(arr2[j++]);
        }
        else
        {
            prev = arr1[i];
            arr.push_back(arr1[i++]);
        }
        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                if (prev == arr1[i])
                    i++;
                else
                {
                    prev = arr1[i];
                    arr.push_back(arr1[i++]);
                }
            }
            else if (arr1[i] > arr2[j])
            {
                if (prev == arr2[j])
                    j++;
                else
                {
                    prev = arr2[j];
                    arr.push_back(arr2[j++]);
                }
            }
        }
        while (i < n)
        {
            if (prev == arr1[i])
                i++;
            else
            {
                prev = arr1[i];
                arr.push_back(arr1[i++]);
            }
        }
        while (j < m)
        {
            if (prev == arr2[j])
                j++;
            else
            {
                prev = arr2[j];
                arr.push_back(arr2[j++]);
            }
        }
        // sort(arr.begin(),arr.end());
        // arr.erase(unique(arr.begin(), arr.end()), arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int N, M;
        cin >> N >> M;

        int arr1[N];
        int arr2[M];

        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        vector<int> ans = ob.findUnion(arr1, arr2, N, M);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends