#include<iostream>
using namespace std;
#include<string.h>
class Solution {
public:
    void minStr(std::string& s) {
        string result;
        for (char c : s) {
            if (!result.empty() && c == ']' && result.back() == '[') {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        s =result;
    }

    int minSwaps(string s) {
        minStr(s);
        int remLen = s.length() / 2;

        if (remLen % 2 == 0)
            return remLen / 2;
        else
            return (remLen / 2) + 1;
    }
};