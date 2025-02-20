#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <numeric>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <ctime>
using namespace std;
vector<int> selection_sort(vector<int> &nums)
{
    // Find minimum then swap it
    // its mean first select mini than swap if;
    // Slection sort
    // B->A->W case (TC): O(n^2);
    // space complexity (SC): O(1);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int miniIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[miniIndex])
            {
                miniIndex = j;
            }
        }
        if (miniIndex != i)
        {
            swap(nums[i], nums[miniIndex]);
        }
    }

    return nums;
}
int main()
{
    return 0;
}