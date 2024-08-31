class Solution
{
public:
    // THIS QUESTION IS EXTENDED VERSION OF N/2 FOR MOORE VOTING ALGO
    vector<int> majorityElement(vector<int> &nums)
    {
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // nums[i] != ele2 because not taken ele1==ele2
            if (cnt1 == 0 && nums[i] != ele2)
            {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != ele1)
            {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if (ele1 == nums[i])
                cnt1++;
            else if (ele2 == nums[i])
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        int times = (int)(nums.size() / 3) + 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == ele1)
                cnt1++;
            if (nums[i] == ele2)
                cnt2++;
        }

        vector<int> ans;
        if (cnt1 >= times)
            ans.push_back(ele1);
        if (cnt2 >= times)
            ans.push_back(ele2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};