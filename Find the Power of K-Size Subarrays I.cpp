class Solution
{
public:
    bool isSortedAndConsecutive(queue<int> q)
    {
        if (q.size() <= 1)
            return true;

        int prev = q.front();
        q.pop();

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (prev > curr)
                return false;
            if (curr - prev != 1)
                return false;

            prev = curr;
        }

        return true;
    }
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        vector<int> ans;
        queue<int> q;

        for (int i = 0; i < k; i++)
        {
            q.push(nums[i]);
        }

        if (isSortedAndConsecutive(q))
        {
            ans.push_back(q.back());
        }
        else
        {
            ans.push_back(-1);
        }

        for (int i = k; i < nums.size(); i++)
        {
            q.pop();
            q.push(nums[i]);
            if (isSortedAndConsecutive(q))
            {
                ans.push_back(q.back());
            }
            else
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};