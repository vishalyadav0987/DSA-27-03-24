/*
Here's how bubble sort works:

Start with the first element of the list.
Compare the current element with the next element.
If the current element is greater than the next element, swap them.
Move to the next pair of elements and repeat steps 2 and 3.
Continue this process until the end of the list is reached.
If any swaps were made during the pass through the list, repeat steps 1-5.
If no swaps were made during the pass through the list, the list is sorted, and the algorithm terminates.
*/

//{ Driver Code Starts
// Initial Template for C++

// C program for implementation of Bubble sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// swapping the elements
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Your code here
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout<<arr[i]<<" ";
        // }
    }
};

//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000], n, T, i;

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;

        ob.bubbleSort(arr, n);
        printArray(arr, n);
    }
    return 0;
    ;
}
// } Driver Code Ends