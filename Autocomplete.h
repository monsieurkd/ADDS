#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class AutoComplete {
private:
    TrieNode* root;

    void insertWord(string word);
    void getAllWords(TrieNode* node, string prefix, vector<string>& suggestions);

public:
    AutoComplete();
    vector<string> getSuggestions(string partialWord);
    void insert(string word);
};

#endif // AUTOCOMPLETE_H
