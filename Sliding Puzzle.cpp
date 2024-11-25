class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        // doing with string using bfs
        // finding all possible place from 0 will swap
        // if any point equal to target "123450"
        // then return the level

        string start = "";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                start += to_string(board[i][j]);
            }
        }

        // Toatal possible newState is 6!
        // to find all possible casse with displace zero
        // tc = O(!(2*3)) = O(6!);
        // sc = O(!(2*3)) = O(6!);

        string target = "123450";

        queue<string> q;
        q.push(start);

        unordered_set<string> visited;
        visited.insert(start);

        unordered_map<int, vector<int>> mpp;
        // agar 0 th index pe hai toh kha kha ja sakta hai and so on
        mpp[0] = {1, 3};
        mpp[1] = {0, 2, 4};
        mpp[2] = {1, 5};
        mpp[3] = {0, 4};
        mpp[4] = {1, 3, 5};
        mpp[5] = {4, 2};

        int level = 0;
        while (!q.empty())
        {
            int n = q.size();

            while (n--)
            {
                string curr = q.front();
                q.pop();

                if (curr == target)
                {
                    return level;
                }

                // finding index of zero then will swap
                // with ther postion seen in map
                int idxOfZero = curr.find('0');
                for (auto swapsIdx : mpp[idxOfZero])
                {
                    string newState = curr;
                    swap(newState[swapsIdx], newState[idxOfZero]);
                    // check in visited this is state present or not
                    if (visited.find(newState) == visited.end())
                    {
                        visited.insert(newState);
                        q.push(newState);
                    }
                }
            }

            level++;
        }

        return -1;
    }
};