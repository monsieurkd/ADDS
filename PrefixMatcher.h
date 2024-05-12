#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int routerNumber;

    TrieNode();

    ~TrieNode();
};

class PrefixMatcher {
private:
    TrieNode* root;

    void insertAddress(string address, int routerNumber);

public:
    PrefixMatcher();

    int selectRouter(string networkAddress);

    void insert(string address, int routerNumber);

    ~PrefixMatcher();
};

#endif // PREFIXMATCHER_H
