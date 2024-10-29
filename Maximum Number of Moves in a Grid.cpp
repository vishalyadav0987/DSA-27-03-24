class Solution
{
public:
    bool isSafe(vector<vector<int>> &grid, int n, int m, int value, int x,
                int y)
    {
        if (((x >= 0) && (x < n)) && ((y >= 0) && (y < m)) &&
            (value < grid[x][y]))
        {
            return true;
        }
        return false;
    }
    int checkPath(vector<vector<int>> &grid, int n, int m, int x, int y,
                  int value, vector<vector<int>> &dp)
    {
        // Check for base condition
        // x = row
        // y = col
        if ((x < 0) || (x == n) || (y == m))
        {
            return 0;
        }
        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }
        int ud = 0, ryt = 0, ld = 0;

        // upper  (row - 1, col + 1)
        int newX = x - 1;
        int newY = y + 1;
        if (isSafe(grid, n, m, value, newX, newY))
        {

            ud = checkPath(grid, n, m, newX, newY, grid[newX][newY], dp);
        }
        // side right   (row, col + 1)
        newX = x;
        newY = y + 1;
        if (isSafe(grid, n, m, value, newX, newY))
        {

            ryt = checkPath(grid, n, m, newX, newY, grid[newX][newY], dp);
        }
        // right lower   (row+1, col + 1)
        newX = x + 1;
        newY = y + 1;
        if (isSafe(grid, n, m, value, newX, newY))
        {
            ld = checkPath(grid, n, m, newX, newY, grid[newX][newY], dp);
        }

        return dp[x][y] = 1 + max({ud, ryt, ld});
    }
    int maxMoves(vector<vector<int>> &grid)
    {
        int maxCount = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            int value = grid[i][0];
            int maxPathCnt = checkPath(grid, n, m, i, 0, value, dp) - 1;
            maxCount = max(maxPathCnt, maxCount);
        }

        return maxCount;
    }
};