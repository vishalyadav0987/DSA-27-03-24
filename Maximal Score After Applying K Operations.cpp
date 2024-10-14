class Solution {
public:
    pair<int, int> maxInd(vector<int>& nums) {
        int maxi = INT_MIN;
        int maxiIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                maxiIndex = i;
            }
        }
        return std::make_pair(maxi, maxiIndex);
    }
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < nums.size(); i++) {
            maxHeap.push({nums[i], i});
        }
        long long sc = 0;

        for (int op = 1; op <= k; op++) {
            // Get the maximum value and its index
            pair<int, int> maxiVal = maxHeap.top();
            maxHeap.pop(); // replace 
            sc += maxiVal.first;
            long long st = static_cast<long long>(
                ceil(static_cast<double>(maxiVal.first) / 3.0));
            maxHeap.push({static_cast<int>(st), maxiVal.second});
        }

        return sc;
    }
};