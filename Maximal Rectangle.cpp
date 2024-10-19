class Solution
{
public:
    vector<int> nextSmallereElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallereElement(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < arr.size(); i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallereElement(heights, n); // loop from last
        vector<int> prev(n);
        prev = prevSmallereElement(heights, n); // loop from start

        int area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            area = max(area, (l * b));
        }

        return area;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        // if (matrix.empty())
        //     return 0;
        // int m = matrix[0].size();
        // int n = matrix.size();
        // // comput the area of first row
        // int area = largestRectangleArea(matrix[0]);
        // // computer area of another row by adding previous row
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; i < m; j++) {
        //         // row updating by previous row
        //         if (matrix[i][j] != 0)
        //             matrix[i][j] = matrix[i][j] + matrix[i - 1][j];
        //         else
        //             matrix[i][j] = 0;
        //     }

        //     // calcutate area for update row
        //     int maxArea = largestRectangleArea(matrix[i]);
        //     area = max(area, maxArea);
        // }
        // return area;

        // see uper code for better understading
        if (matrix.empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        // First row heights
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            // Update heights based on the current row
            for (int j = 0; j < m; j++)
            {
                // Convert '1' to 1 and '0' to 0 in heights
                if (matrix[i][j] == '1')
                {
                    heights[j] += 1;
                }
                else
                {
                    heights[j] = 0;
                }
            }

            // Calculate max area for this row's histogram
            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// space complexity o(m== col.size);
// tc o(n^m)