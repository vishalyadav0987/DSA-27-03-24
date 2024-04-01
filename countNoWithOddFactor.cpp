//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int count(int N)
    {
        // code here
        int countOdd = 0;
        for (int i = 1; i <= N; i++)
        {
            int root = sqrt(i);
            if (root * root == i)
            {
                countOdd++;
            }
        }
        return countOdd;
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
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0;
}
// } Driver Code Ends

// CONDITION
/*
This function countNumbersWithOddFactors takes an integer N as input and returns the count of numbers from 1 to N that have an odd number of factors.

It initializes a variable count to store the count of numbers with odd factors.
It iterates through each number from 1 to N using a for loop.
For each number i, it calculates the square root (root) using the sqrt function from the cmath library.
If the square of root is equal to i, then i is a perfect square, and it has an odd number of factors. In this case, it increments the count variable.
Finally, it returns the count of numbers with odd factors.
*/