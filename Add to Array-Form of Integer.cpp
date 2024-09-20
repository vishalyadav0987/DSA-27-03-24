#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int carry = 0;
        int i = num.size() - 1;
        vector<int> v;
        // i==j
        while (i >= 0 && k != 0)
        {
            int sum = ((num[i] + (k % 10))) + carry;
            carry = sum / 10;
            sum = sum % 10;
            v.push_back(sum);
            i--;
            k = k / 10;
        }
        // i>j
        while (i >= 0)
        {
            int sum = ((num[i] + (k % 10))) + carry;
            carry = sum / 10;
            sum = sum % 10;
            v.push_back(sum);
            i--;
        }

        while (carry != 0 || k != 0)
        {
            int sum = carry + (k % 10);
            carry = sum / 10;
            sum = sum % 10;
            v.push_back(sum);
            k /= 10;
        }

        reverse(v.begin(), v.end());
        return v;
    }
};