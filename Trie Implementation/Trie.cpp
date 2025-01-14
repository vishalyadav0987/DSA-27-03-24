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
    char data;
    TrieNode *children[26];
    bool isTreminal;

    TrieNode(char ch)
    {
        data = ch;
        isTreminal = false;
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
    Trie()
    {
        root = new TrieNode('\0');
    }

    // solving using recursion
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            // where i stop when i searching a word
            root->isTreminal = true;
            return;
        }

        // first find word root index
        int index = word[0] - 'a';
        TrieNode *child;

        // present - simple move that root -- so on
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // if absent -- simple create and move futher
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // because hum 0th index word ke liye phle hi kar chuke hai
        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    // solving using recursion
    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            // where i stop when i searching a word
            return root->isTreminal;
        }

        // first find word root index
        int index = word[0] - 'a';
        TrieNode *child;

        // present - simple move that root -- so on
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // if absent -- simple create and move futher
            return false;
        }

        // because hum 0th index word ke liye phle hi kar chuke hai
        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    // solving using recursion
    bool prefixUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            // where i stop when i searching a word
            return true;
        }

        // first find word root index
        int index = word[0] - 'a';
        TrieNode *child;

        // present - simple move that root -- so on
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // if absent -- simple create and move futher
            return false;
        }

        // because hum 0th index word ke liye phle hi kar chuke hai
        return prefixUtil(child, word.substr(1));
    }

    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main()
{
    return 0;
}