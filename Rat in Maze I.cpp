//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isSafe(int x, int y, vector<vector<int>> &visited, int n, vector<vector<int>> &mat)
    {
        if (((x >= 0) && (x < n)) && ((y >= 0) && (y < n)) && visited[x][y] == 0 && mat[x][y] == 1)
        {
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &mat, vector<string> &ans, string path, int x, int y, vector<vector<int>> &visited, int n)
    {

        // Check for base condition
        // reach to destination
        if ((x == n - 1) && (y == n - 1))
        {
            ans.push_back(path);
            return;
        }

        // when find 1 in mat mark true in visited array;
        visited[x][y] = 1;

        // Check where i go; means checking for 1;
        // D/L/R/U

        // Down
        int newX = x + 1;
        int newY = y;
        if (isSafe(newX, newY, visited, n, mat))
        {
            path.push_back('D');
            solve(mat, ans, path, newX, newY, visited, n);
            path.pop_back();
        }

        // LEFT
        newX = x;
        newY = y - 1;
        if (isSafe(newX, newY, visited, n, mat))
        {
            path.push_back('L');
            solve(mat, ans, path, newX, newY, visited, n);
            path.pop_back();
        }

        // RIGHT
        newX = x;
        newY = y + 1;
        if (isSafe(newX, newY, visited, n, mat))
        {
            path.push_back('R');
            solve(mat, ans, path, newX, newY, visited, n);
            path.pop_back();
        }

        // UP
        newX = x - 1;
        newY = y;
        if (isSafe(newX, newY, visited, n, mat))
        {
            path.push_back('U');
            solve(mat, ans, path, newX, newY, visited, n);
            path.pop_back();
        }

        // when we going to back then we visted will 0
        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &mat)
    {
        // Your code goes here
        vector<string> ans;
        if (mat[0][0] == 0)
        {
            return ans;
        }

        // initial point
        int srcX = 0;
        int srcY = 0;

        string path = "";

        int n = mat.size(); // n*n

        vector<vector<int>> visited = mat;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }

        solve(mat, ans, path, srcX, srcY, visited, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends