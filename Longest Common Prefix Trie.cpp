#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <numeric>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <ctime>
using namespace std;
class TrieNode
{
public:
    // tc o(l*n);
    // sc o(l*n);
    char data;
    bool isTerminal;
    TrieNode *children[26];
    int childCount;
    // each root have how many child
    // if every root that i am check that have 1 child it means
    // it is common prefix for every string
    TrieNode(char ch)
    {
        data = ch;
        isTerminal = false;
        childCount = 0;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char d) { root = new TrieNode(d); }

    // insert all word that present in list
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // finding position
        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            // move furhter
            child = root->children[index];
        }
        else
        {
            // absent then creter
            //  and insert and increae child count
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursive
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) { insertUtil(root, word); }

    void lcp(string firstWord, string &ans)
    {
        for (int i = 0; i < firstWord.length(); i++)
        {
            char ch = firstWord[i];

            if (root->childCount == 1)
            {
                ans.push_back(firstWord[i]);
                // aur root ko aage badao
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
            {
                break;
            }
        }
    }
};
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // Using trie

        Trie *t = new Trie('\0');

        int n = strs.size();
        // insert all words
        for (int i = 0; i < n; i++)
        {
            if (strs[i] != "")
            {
                t->insertWord(strs[i]);
            }
            else
            {
                return "";
            }
        }

        string firstWord = strs[0];
        string ans = "";

        t->lcp(firstWord, ans);

        return ans;
    }
};
int main()
{
    return 0;
}