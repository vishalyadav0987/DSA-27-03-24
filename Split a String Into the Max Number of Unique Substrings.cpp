class Solution
{
public:
    // this question neccesarliy using bactracking
    void solve(string s, int i, unordered_set<string> &st, int &maxCnt,
               int currCnt)
    {
        if (i >= s.length())
        {
            maxCnt = max(currCnt, maxCnt);
            return;
        }
        // explore all the string from i to j
        for (int j = i; j < s.length(); j++)
        {
            string sub = s.substr(i, j - i + 1); // o(n)
            if (st.find(sub) == st.end())
            {
                st.insert(sub); // Do insert unique sub string in set
                solve(s, j + 1, st, maxCnt,
                      currCnt + 1); // EXPLORE ALL REM STRING
                // backtracking
                // remove all the substring from the set
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s)
    {
        unordered_set<string> st;
        int maxCnt = 0;
        int currCnt = 0;
        int i = 0;
        solve(s, i, st, maxCnt, currCnt);
        return maxCnt;
    }
};