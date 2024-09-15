#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // if convert to lineat array
        // [1,3,5,7,10,11,16,20,23,30,34,60]
        //  0,1,2,3, 4, 5, 6,,7, 8, 9,10, 11
        // mid = 0+11/2 = 5 // 1d array ---> mid = 11
        // mid in 2d array = mid=arr[mid/sizeOfCol][mid%sizeOfCol]
        // col = 4
        // mid=[6/4][6%4] ---> mid[1][2] = 11

        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        int low = 0;
        int high = rowLen * colLen - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int element = matrix[mid / colLen][mid % colLen];
            if (element == target)
            {
                return true;
            }
            else if (element < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};