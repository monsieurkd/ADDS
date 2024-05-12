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

class Autocomplete {
private:
    TrieNode* root;

    void insertWord(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c]) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    void getAllWords(TrieNode* node, string prefix, vector<string>& suggestions) {
        if (node->isEndOfWord) {
            suggestions.push_back(prefix);
        }
        for (auto& it : node->children) {
            getAllWords(it.second, prefix + it.first, suggestions);
        }
    }

public:
    Autocomplete() {
        root = new TrieNode();
    }

    vector<string> getSuggestions(string partialWord) {
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

    void insert(string word) {
        insertWord(word);
    }
};

int main() {
    Autocomplete autocomplete;
    autocomplete.insert("bin");
    autocomplete.insert("ball");
    autocomplete.insert("ballet");

    vector<string> suggestions;

    // User types 'b'
    suggestions = autocomplete.getSuggestions("b");
    cout << "Suggestions for 'b':" << endl;
    for (const string& s : suggestions) {
        cout << s << endl;
    }
    cout << endl;

    // User types 'ba'
    suggestions = autocomplete.getSuggestions("ba");
    cout << "Suggestions for 'ba':" << endl;
    for (const string& s : suggestions) {
        cout << s << endl;
    }
    cout << endl;

    // User types 'bal'
    suggestions = autocomplete.getSuggestions("bal");
    cout << "Suggestions for 'bal':" << endl;
    for (const string& s : suggestions) {
        cout << s << endl;
    }
    cout << endl;

    // User types 'balle'
    suggestions = autocomplete.getSuggestions("balle");
    cout << "Suggestions for 'balle':" << endl;
    for (const string& s : suggestions) {
        cout << s << endl;
    }

    return 0;
}
