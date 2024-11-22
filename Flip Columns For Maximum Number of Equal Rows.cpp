class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        // step 1 : iterate from each row
        // step 2 : check another it have same or inverted of this row
        // step 3 : if have then
        // step 4 :

        // 1 0 0 0 1 = a
        // 0 1 1 1 0 = b
        // 1 0 0 0 1 = c
        // 1 0 1 0 1 = d

        // we know that in step 2 check
        // a = b is inverted of a
        // a = c is equal to a

        // then make to equal fliped column

        // make 1st ans last col fliped

        // 0 0 0 0 0
        // 1 1 1 1 1
        // 0 0 0 0 0
        // 0 0 1 0 0

        // 1st 3 rows have have same value

        int m = matrix.size();    // row size
        int n = matrix[0].size(); // col size

        int maxRowSame = 0;

        // o(m * (n + (m * n)));

        // overall worst case = O(m * n * m);

        for (auto currRow : matrix)
        {                               // o(m)
            vector<int> invertedRow(n); // inveterd the row that have check
            for (int j = 0; j < n; j++)
            { // o(n)
                invertedRow[j] = currRow[j] == 0 ? 1 : 0;
            }

            // then search in matrix
            int cnt = 0;
            for (auto row : matrix)
            { // o(m)
                if (row == currRow || row == invertedRow)
                { // o(n)
                    cnt++;
                }
            }

            maxRowSame = max(maxRowSame, cnt);
        }

        return maxRowSame;
    }
};