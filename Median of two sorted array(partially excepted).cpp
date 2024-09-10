#include <bits/stdc++.h>
using namespace std;
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
        int i = 0;
        int j = 0;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = n1 + n2;
        int index1 = (n / 2) - 1;
        int index2 = n / 2;
        int cnt = 0;
        int med1 = -1;
        int med2 = -1;
        while (i < n1 && j < n2)
        {
            if (arr1[i] < arr2[j])
            {
                if (cnt == index1)
                    med1 = arr1[i];
                if (cnt == index2)
                    med2 = arr1[i];
                cnt++;
                i++;
            }
            else
            {
                if (cnt == index1)
                    med1 = arr2[j];
                if (cnt == index2)
                    med2 = arr2[j];
                cnt++;
                j++;
            }
        }

        while (i < n1)
        {
            if (cnt == index1)
                med1 = arr1[i];
            if (cnt == index2)
                med2 = arr1[i];
            cnt++;
            i++;
        }
        while (j < n2)
        {
            if (cnt == index1)
                med1 = arr2[j];
            if (cnt == index2)
                med2 = arr2[j];
            cnt++;
            j++;
        }

        if (n % 2 == 1)
        {
            return med2;
        }
        else
        {
            return (double)((double)med1 + med2) / 2.0;
        }
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