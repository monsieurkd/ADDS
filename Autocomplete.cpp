#include "Autocomplete.h"

void Autocomplete::insertWord(string word) {
    TrieNode* current = root;
    for (char c : word) {
        if (!current->children[c]) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true;
}

void Autocomplete::getAllWords(TrieNode* node, string prefix, vector<string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }
    for (auto& it : node->children) {
        getAllWords(it.second, prefix + it.first, suggestions);
    }
}

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

vector<string> Autocomplete::getSuggestions(string partialWord) {
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

void Autocomplete::insert(string word) {
    insertWord(word);
}
