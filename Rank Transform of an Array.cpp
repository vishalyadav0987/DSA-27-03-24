#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKeyByValue(vector<pair<int, int>> &vec, int value)
    {

        for (const auto &pair : vec)
        {
            if (pair.second == value)
            {
                return pair.first;
            }
        }

        return -1;
    }
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<pair<int, int>> vec;
        map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++)
        {
            vec.push_back({i, arr[i]});
        }
        sort(vec.begin(), vec.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.second < b.second;
             });

        vector<int> ranks(arr.size());
        int rank = 1;
        for (int i = 0; i < vec.size(); i++)
        {
            if (i == 0 || vec[i].second != vec[i - 1].second)
            {
                ranks[vec[i].first] = rank++;
            }
            else
            {
                ranks[vec[i].first] = ranks[vec[i - 1].first];
            }
        }

        return ranks;
    }
};