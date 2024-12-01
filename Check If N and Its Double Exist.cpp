class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        map<int, int> mp;
        mp[arr[0]] = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (mp.find(2 * arr[i]) != mp.end())
                return true;
            if (mp.find(arr[i] / 2) != mp.end())
            {
                // index these element/2 from map
                // then double and == to present elemnt
                // in array have or not
                int idx = mp[arr[i] / 2];
                if (arr[idx] * 2 == arr[i])
                    return true;
            }
            mp[arr[i]] = i;
        }
        return false;
    }
};