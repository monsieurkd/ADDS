#include "prefixmatcher.h"

TrieNode::TrieNode() : routerNumber(-1) {}

TrieNode::~TrieNode() {
    for (auto& pair : children) {
        delete pair.second;
    }
}

PrefixMatcher::PrefixMatcher() {
    root = new TrieNode();
}

void PrefixMatcher::insertAddress(string address, int routerNumber) {
    TrieNode* current = root;
    for (char c : address) {
        if (!current->children[c]) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(string networkAddress) {
    TrieNode* current = root;
    int selectedRouter = -1;
    for (char c : networkAddress) {
        if (!current->children[c]) {
            break;
        }
        current = current->children[c];
        if (current->routerNumber != -1) {
            selectedRouter = current->routerNumber;
        }
    }
    return selectedRouter;
}

void PrefixMatcher::insert(string address, int routerNumber) {
    insertAddress(address, routerNumber);
}

PrefixMatcher::~PrefixMatcher() {
    delete root;
}
