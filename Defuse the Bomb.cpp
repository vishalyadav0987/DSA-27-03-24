class Solution
{
public:
    void kGreaterThan0(vector<int> &code, vector<int> &ans, int k)
    {
        int n = code.size();
        int sum = 0;
        int ayega = 0;
        for (int i = 1; i <= k; i++)
        {
            sum += code[i];
            ayega = i + 1;
        }
        ans.push_back(sum);
        for (int i = 1; i < code.size(); i++)
        {
            sum = sum - code[(i) % n] + code[(i + k) % n];
            ans.push_back(sum);
        }
    }
    void kLessThan0(vector<int> &code, vector<int> &ans, int k)
    {
        k = abs(k);
        int n = code.size();
        int sum = 0;
        int last = 0; // index
        int p = 0;    // value
        for (int i = 0; i < k; i++)
        {
            sum += code[n - i - 1];
            last = n - i - 1;
        }
        ans.push_back(sum);
        // sum same
        // last same
        p = code[0];
        for (int i = 1; i < code.size(); i++)
        {
            sum = sum - code[last] + p;
            ans.push_back(sum);

            // Update the last index with wraparound
            last = (last + 1) % n;
            p = code[i];
        }
    }
    vector<int> decrypt(vector<int> &code, int k)
    {
        vector<int> ans;
        if (k > 0)
        {
            kGreaterThan0(code, ans, k);
        }
        else if (k == 0)
        {
            fill(code.begin(), code.end(), 0);
            return code;
        }
        else if (k < 0)
        {
            kLessThan0(code, ans, k);
        }

        return ans;
    }
};