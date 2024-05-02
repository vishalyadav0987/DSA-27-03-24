//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        // code here
        // next_permutation(arr.begin(),arr.end()); // this stl slution this btter approch not optimal

        // agar hub dip hle se check karenge toh iska matlab woh humara answer hai
        // toh hum last 2nd se check karenge
        int index = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            reverse(arr.begin(), arr.end());
            return arr;
        }
        // agar hum dip milega toh ab hun check sab chote aurke karib elemnt ko swap kareng
        for (int i = n - 1; i >= index; i--)
        {
            if (arr[i] > arr[index])
            {
                swap(arr[i], arr[index]);
                break;
            }
        }
        // fir revese kar denge index ke baad ke saare elemnent ko
        reverse(arr.begin() + index + 1, arr.end());
        return arr;
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for (int u : ans)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends