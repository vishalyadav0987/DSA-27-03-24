#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string output, vector<string> &ans, string mapping[], int index)
{
    // base condition
    if (index >= 2)
    {
        ans.push_back(output);
        return;
    }

    int number = (int)(digits[index] - '0');
    string word = mapping[number];
    // 2 -> abc
    // 3 -> def
    for (int i = 0; i < 3; i++)
    {
        output.push_back(word[i]);
        solve(digits, output, ans, mapping, index + 1);
        output.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    string output = "";
    vector<string> ans;
    if (digits.length() == 0)
        return ans;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, ans, mapping, 0);
    return ans;
}

int main()
{
    string s = "23";
    vector<string> g = letterCombinations(s);
    for (auto elm:g)
    {
        cout<<elm << " ";
    }
    

    return 0;
}