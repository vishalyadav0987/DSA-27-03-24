class Solution
{
public:
    static bool customCompare(int a, int b)
    {
        int cnt1 = __builtin_popcount(a);
        int cnt2 = __builtin_popcount(b);

        return (cnt1 == cnt2 && a < b);
    }
    bool canSortArray(vector<int> &nums)
    {
        stable_sort(nums.begin(), nums.end(), customCompare);

        return is_sorted(begin(nums), end(nums));
    }
};