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
    int n = arr.size();
    // 3. Insertion Sort
    // Best TC: O(n)
    // Worst and Avg Tc: O(n^2);
    // SC: O(1)
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Pick the current element
        int j = i - 1;
        // Shift elements to the right to find the correct position for key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Place key in its correct position
    }

    return arr;
}
int main()
{
    return 0;
}