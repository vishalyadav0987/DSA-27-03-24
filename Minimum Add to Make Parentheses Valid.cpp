class Solution {
public:
    void removeValid(string& s) {
        string str;
        for (char ch : s) {
            if (!str.empty() && ch == ')' && str.back() == '(') {
                str.pop_back();
            } else {
                str.push_back(ch);
            }
        }
        s = str;
    }
    int minAddToMakeValid(string s) {
        removeValid(s);
        int imbalance = 0;
        for (char ch : s) {
            if (ch == '(') {
                imbalance++;
            } else if (ch == ')') {
                imbalance++;
            }
        }
        return imbalance;
    }
};