#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    void arrayFun(const string& sentence, vector<string>& arr) {
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.length() > sentence2.length()) {
            return areSentencesSimilar(sentence2, sentence1);
        }

        vector<string> smaller;
        vector<string> larger;
        arrayFun(sentence1, smaller);
        arrayFun(sentence2, larger);
        
        int i = 0;
        int j = smaller.size() - 1;
        int j1 = larger.size() - 1;

        // Prefix check
        while (i <= j && smaller[i] == larger[i]) {
            i++;
        }

        // Suffix check
        while (i <= j && smaller[j] == larger[j1]) {
            j--;
            j1--;
        }

        return (i > j);
    }
};
 ̰