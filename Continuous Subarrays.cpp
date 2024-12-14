class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        map<int, int> mpp;
        // map size not increase grater than 3
        // sc = o(3) ~= o(1);
        // tc = n * log(3) ~= o(n);
        // log(3) = erase from mapp
        int i = 0;
        int j = 0;
        long long ansCnt = 0LL;
        while (j < nums.size())
        {
            mpp[nums[j]]++;
            // max and maxi element from map
            while (abs(mpp.rbegin()->first - mpp.begin()->first) > 2)
            {
                //  if any case it out of boud
                // then shrink the window from left side
                // increse i++
                // jis pe phle i tha uski freq ko 0 karde
                // aur usko erase kar denge
                mpp[nums[i]] -= 1;
                if (mpp[nums[i]] == 0)
                {
                    mpp.erase(nums[i]);
                }
                i++;
            }
            ansCnt += j - i + 1;
            j++;
        }
        return ansCnt;
    }
};