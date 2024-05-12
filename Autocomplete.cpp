#include "Autocomplete.h"

void AutoComplete::insertWord(string word) {
    TrieNode* current = root;
    for (char c : word) {
        if (!current->children[c]) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true;
}

void AutoComplete::getAllWords(TrieNode* node, string prefix, vector<string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }
    for (auto& it : node->children) {
        getAllWords(it.second, prefix + it.first, suggestions);
    }
}

AutoComplete::AutoComplete() {
    root = new TrieNode();
}

vector<string> AutoComplete::getSuggestions(string partialWord) {
    TrieNode* current = root;
    vector<string> suggestions;
    for (char c : partialWord) {
        if (!current->children[c]) {
            return suggestions;
        }
        current = current->children[c];
    }
    getAllWords(current, partialWord, suggestions);
    return suggestions;
}

void AutoComplete::insert(string word) {
    insertWord(word);
}
