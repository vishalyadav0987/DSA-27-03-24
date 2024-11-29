#include <bits/stdc++.h>
using namespace std;

int minExtraChar(string s, vector<string>& dictionary) {
    for (const auto& word : dictionary) {
        size_t found = s.find(word);
        while (found != string::npos) {
            s.erase(found, word.length());
            found = s.find(word); // Update found correctly
        }
    }
    return s.length(); // Return the length of the modified string
}

int main() {
    vector<string> arr = {"hello", "world"x`}; // Use vector for the dictionary
    string s = "sayhelloworld";
    int n = minExtraChar(s, arr);
    cout << n; // Output the result
    return 0;
}
