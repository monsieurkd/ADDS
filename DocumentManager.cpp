// DocumentManager.cpp
#include "DocumentManager.h"
#include <iostream>

void DocumentManager::addDocument(const std::string& name, int id, int license_limit) {
    if (docNameToID.find(name) != docNameToID.end()) {
        std::cerr << "Document with this name already exists." << std::endl;
        return;
    }
    docNameToID[name] = id;
    documents[id] = {name, license_limit, 0};
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
}

int DocumentManager::search(const std::string& name) {
    auto it = docNameToID.find(name);
    if (it != docNameToID.end()) {
        return it->second;
    }
    return 0; // Document not found
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (patrons.find(patronID) == patrons.end()) {
        return false; // Patron not registered
    }
    auto docIt = documents.find(docid);
    if (docIt == documents.end()) {
        return false; // Document not found
    }
    Document& doc = docIt->second;
    if (doc.currentlyBorrowed < doc.license_limit) {
        if (borrowedDocs[docid].insert(patronID).second) {
            doc.currentlyBorrowed++;
            return true; // Document successfully borrowed
        }
    }
    return false; // Document limit reached or already borrowed by this patron
}

void DocumentManager::returnDocument(int docid, int patronID) {
    auto docIt = documents.find(docid);
    if (docIt == documents.end()) {
        return; // Document not found
    }
    Document& doc = docIt->second;
    if (borrowedDocs[docid].erase(patronID)) {
        doc.currentlyBorrowed--;
    }
}
