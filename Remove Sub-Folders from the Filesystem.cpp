class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        vector<string> ans; // for storing answer

        // fistly sort the array
        sort(folder.begin(), folder.end());
        ans.push_back(
            folder[0]); // push first value of array because itrate then compare
        for (int i = 1; i < folder.size(); i++)
        {

            // take last value of ans array then compare it
            string last = ans.back();
            cout << last << " ";
            last.push_back('/'); // push it because check at last char not match

            // compare to string
            // if not match then push it
            if (folder[i].compare(0, last.size(), last) !=
                0) // this codn for not match
                ans.push_back(folder[i]);
        }
        return ans;
    }
};