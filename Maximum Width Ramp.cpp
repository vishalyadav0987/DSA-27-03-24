class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // using monotonic stack
        // this type of stack using for stre element in decresing order;
        int n = nums.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty() || (nums[s.top()] > nums[i])) {
                s.push(i);
            }
            if (nums[i] == 0)
                break;
        }
        int ans = 0;
        if (s.size() == n)
            return ans;
        for (int j = n - 1; j >= 0; j--) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                ans = max(ans, j - s.top());
                s.pop();
            }
        }

        return ans;
    }
};