//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string reverseWord(string str)
    {
        // Your code goes here
        // string s = "";
        // for(int i = str.length() - 1; i >= 0; i--){
        //     s += str[i];
        // }
        // return s;
        int i = 0;
        int j = str.length() - 1;
        while (i < j)
        {
            swap(str[i], str[j]);
            i++;
            j--;
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.reverseWord(s) << endl;
    }
    return 0;
}

// } Driver Code Ends