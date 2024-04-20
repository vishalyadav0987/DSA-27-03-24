//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    void merge(int arr[], int l, int mid, int h)
    {
        // Your code here
        vector<int> ans;
        int i = l;       // starting point 1st array
        int j = mid + 1; // starting point 2nd array
        while (i <= mid && j <= h)
        {
            if (arr[i] < arr[j])
            {
                ans.push_back(arr[i]);
                i++;
            }
            else
            {
                ans.push_back(arr[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            ans.push_back(arr[i]);
            i++;
        }
        while (j <= h)
        {
            ans.push_back(arr[j]);
            j++;
        }
        for (int k = l; k <= h; k++)
        {
            arr[k] = ans[k - l];
        }
    }

public:
    void mergeSort(int arr[], int l, int h)
    {
        // code here
        if (l >= h)
            return;
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);     // divide the array
        mergeSort(arr, mid + 1, h); // divide the array
        merge(arr, l, mid, h);
    }
};

//{ Driver Code Starts.

int main()
{
    int n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);
        int arr[n + 1];
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.mergeSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends