//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string calc_Sum(vector<int> &arr1, vector<int> &arr2)
    {
        // Complete the function
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        vector<int> v;
        int carry = 0;
        string ans = "";
        // case 1 when i==j
        while (i >= 0 && j >= 0)
        {
            int sum = arr1[i] + arr2[j] + carry;
            carry = sum / 10;
            sum = sum % 10;
            v.push_back(sum);
            i--;
            j--;
        }
        // case 2  i > j
        while (i >= 0)
        {
            int sum = arr1[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            v.push_back(sum);
            i--;
        }
        // case 3  i < j
        while (j >= 0)
        {
            int sum = arr2[j] + carry;
            carry = sum / 10;
            sum = sum % 10;
            v.push_back(sum);
            j--;
        }
        while (carry != 0)
        {
            int sum = carry;
            carry = sum / 10;
            sum = sum % 10;
            v.push_back(sum);
        }
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans += to_string(v[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
/* Driver program to test above function */
int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--)
    {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1)
        {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2)
        {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        // vector<int> v;
        string v = ob.calc_Sum(arr1, arr2);

        // for (int i = 0; i < v.size(); i++)
        //     cout << v[i] << " ";

        // cout << endl;
        cout << v << endl;
        // cout << "~" << endl;
        // string tilde;
        // getline(cin, tilde);
    }

    return 0;
}

// } Driver Code Ends