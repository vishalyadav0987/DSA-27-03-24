class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                zeros++;
            }
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if (i < s.length() && ((s[i] == '1' && s[i + 1] == '0') ||
                                   (s[i] == '1' && s[i + 1] == '1'))) {
                ans += zeros;
            } else {
                zeros--;
            }
        }
        return ans;
    }
};