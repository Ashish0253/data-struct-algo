#include <bits/stdc++.h>
using namespace std;

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

        // assuming all charcters are lowercase
        int idx = word[0] - 'a';
        TrieNode *child;

        // if current character is present in the trie
        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        // if current character is not present in the trie
        else
        {
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {

        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        // assuming all characters are lowercase
        int idx = word[0] - 'a';
        TrieNode *child;

        // if current character is present in the trie
        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }

        // if current character is not present in the trie
        else
        {
            return false;
        }

        // recursive call
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool removeUtil(TrieNode *root, string word)
    {

        // base case
        if (word.length() == 0)
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;
                return true;
            }
            else
            {
                return false;
            }
        }

        // assuming all characters are lowercase
        int idx = word[0] - 'a';
        TrieNode *child;

        // if current character is present in the trie
        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }

        // if current character is not present in the trie i.e. word is not present
        else
        {
            return false;
        }

        // recursive call
        return removeUtil(child, word.substr(1));
    }

    bool removeWord(string word)
    {
        return removeUtil(root, word);
    }
};

int main()
{

    Trie dictionary;

    // insertion
    dictionary.insertWord("apple");
    dictionary.insertWord("arm");
    dictionary.insertWord("do");
    dictionary.insertWord("time");

    // searching words
    cout << dictionary.searchWord("apple") << endl;
    cout << dictionary.searchWord("app") << endl;
    cout << dictionary.searchWord("arm") << endl;
    cout << dictionary.searchWord("time") << endl;

    // removing words
    cout << dictionary.removeWord("applef") << endl;

    // checking if word is removed
    cout << dictionary.searchWord("applef") << endl;

    return 0;
}