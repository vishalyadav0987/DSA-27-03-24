class Solution
{
public:
    bool isValidPath(vector<vector<int>> &matrix, int newX, int newY, int m,
                     int n)
    {
        if (((newX >= 0) && (newX < m)) && ((newY >= 0) && (newY < n)) &&
            matrix[newX][newY] != 2 && matrix[newX][newY] != 3)
        {
            return true;
        }
        else
            return false;
    }
    void bfs(vector<vector<int>> &matrix, vector<vector<int>> &guards, int m,
             int n, vector<vector<bool>> &visited)
    {
        // Down 1,0
        // Left 0,-1
        // Right 0,1
        // Up -1,0
        vector<pair<int, int>> dirn = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

        for (const auto &guard : guards)
        {
            // checking for which direction
            // se the gaurds
            for (auto directions : dirn)
            {
                int newX = guard[0] + directions.first;
                int newY = guard[1] + directions.second;
                while (isValidPath(matrix, newX, newY, m, n))
                {
                    if (!visited[newX][newY])
                    {
                        visited[newX][newY] = true;
                    }
                    newX += directions.first;
                    newY += directions.second;
                }
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>> &guards,
                       vector<vector<int>> &walls)
    {
        vector<vector<int>> matrix(m, vector<int>(n, 1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (const auto &wall : walls)
        {
            int x = wall[0]; // Row index
            int y = wall[1]; // Column index
            if (x >= 0 && x < m && y >= 0 && y < n)
            { // Ensure within bounds
                matrix[x][y] = 2;
            }
        }
        for (const auto &guard : guards)
        {
            int x = guard[0]; // Row index
            int y = guard[1]; // Column index
            if (x >= 0 && x < m && y >= 0 && y < n)
            { // Ensure within bounds
                matrix[x][y] = 3;
            }
        }

        bfs(matrix, guards, m, n, visited);

        int NotSeen = 0;

        for (const auto &row : visited)
        {
            for (int val : row)
            {
                cout << val << " ";
            }
            cout << endl;
        }

        for (const auto &row : visited)
        {
            for (int val : row)
            {
                if (val == 0)
                {
                    NotSeen++;
                }
            }
        }

        return NotSeen - walls.size() - guards.size();
    }
};