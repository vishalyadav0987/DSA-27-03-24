//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long cnt = 0;
    void merge(long long arr[], long long low, long long mid, long long high)
    {
        long long left = low;      // starting index of left half of arr
        long long right = mid + 1; // starting index of right half of arr

        vector<long long> temp(high - low + 1); // temporary array to store merged elements

        long long index = 0; // index for temporary array

        // Merging and counting inversions
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp[index++] = arr[left++];
            }
            else
            {
                temp[index++] = arr[right++];
                cnt += (mid - left + 1); // Increment count when an inversion is found
            }
        }

        // If elements on the left half are still left
        while (left <= mid)
        {
            temp[index++] = arr[left++];
        }

        // If elements on the right half are still left
        while (right <= high)
        {
            temp[index++] = arr[right++];
        }

        // Transfer all elements from temporary to arr
        for (long long i = low, j = 0; i <= high; i++, j++)
        {
            arr[i] = temp[j];
        }
    }

    // Merge sort function
    void mergeSort(long long arr[], long long low, long long high)
    {
        if (low >= high)
            return;
        long long mid = (low + high) / 2;
        mergeSort(arr, low, mid);      // Left half
        mergeSort(arr, mid + 1, high); // Right half
        merge(arr, low, mid, high);    // Merging sorted halves
    }

    long long int inversionCount(long long arr[], long long n)
    {
        mergeSort(arr, 0, n - 1);
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends