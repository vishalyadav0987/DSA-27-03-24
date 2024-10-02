#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        map<int, int> mpp;
        for (auto &i : arr)
        {
            mpp[i]++;
        }
        int rank = 1;
        for (auto &i : mpp)
        {
            i.second = rank++;
        }
        for (auto i : mpp)
        {
            cout << i.first << " " << i.second << endl;
        }
        vector<int> ranks(arr.size());
        int k = 0;
        for (auto &i : arr)
        {
            ranks[k++] = mpp[i];
        }

        return ranks;
    }
};