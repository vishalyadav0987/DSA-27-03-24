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
//{ Driver Code Starts
// Initial Template for C++

using namespace std;

// } Driver Code Ends
// User function Template for C++
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // find index of first char the check present or not in trie
        int index = word[0] - 'a';
        TrieNode *child;

        // if presnt -- simple move to next
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // if absent then create -- then points to the new node child
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursively
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // printSuggestion
    void printSuggestion(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        // finding next word of node
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back(); // when goint upward in trie
            }
        }
    }

    // getSuggestion
    void getSuggestion(string query, vector<vector<string>> &output)
    {
        TrieNode *prev = root;
        string prefix = "";

        for (int i = 0; i < query.length(); i++)
        {
            char lastWord = query[i];

            prefix.push_back(lastWord);

            // check for last word
            TrieNode *curr = prev->children[lastWord - 'a'];

            // if not found
            vector<string> temp;
            if (curr == NULL)
            {
                temp.push_back("0");
                output.push_back(temp);
                break;
            }
            else
            {
                // if char is found
                printSuggestion(curr, temp, prefix);
                output.push_back(temp);
                temp.clear();
                prev = curr;
            }
        }

        while (output.size() < query.size())
        {
            output.push_back({"0"});
        }
    }
};

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie *t = new Trie();

        for (int i = 0; i < n; i++)
        {
            t->insertWord(contact[i]);
        }

        vector<vector<string>> output;
        t->getSuggestion(s, output);

        return output;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < ans.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends