class Solution
{
public:
#define P pair<int, pair<int, int>>
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minimumTime(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // base case
        if (grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}}); // when standing on 0,0
        result[0][0] = 0;     // when standing time = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        while (!pq.empty())
        {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (col == n - 1 && row == m - 1)
            {
                return result[m - 1][n - 1];
            }

            if (visited[row][col])
            {
                continue;
            }
            visited[row][col] = true;

            // for checking possible direction where we go
            for (auto &dirn : directions)
            {
                int x = row + dirn[0];
                int y = col + dirn[1];

                // for valid path
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y])
                {
                    continue;
                }

                if (grid[x][y] <= time + 1)
                {
                    pq.push({time + 1, {x, y}});
                    result[x][y] = time + 1;
                }
                else if ((grid[x][y] - time) % 2 == 0)
                { // even
                    pq.push({grid[x][y] + 1, {x, y}});
                    result[x][y] = grid[x][y] + 1;
                }
                else
                { // odd
                    pq.push({grid[x][y], {x, y}});
                    result[x][y] = grid[x][y];
                }
            }
        }

        return result[m - 1][n - 1];
    }
};