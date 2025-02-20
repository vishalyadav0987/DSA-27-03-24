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
vector<int> sortArray(vector<int> &arr)
{
    // 2. Bubble Sort
    // Best TC: O(n)
    // Worst and Avg Tc: O(n^2);
    // SC: O(1)
    int n = arr.size();
    int isSwap;
    for (int i = 0; i < n - 1; i++)
    {
        isSwap = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if (!isSwap)
        {
            break;
        }
    }
    return arr;
}
int main()
{
    return 0;
}