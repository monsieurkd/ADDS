// DocumentManager.h
#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include <string>
#include <unordered_map>
#include <unordered_set>

class DocumentManager {
public:
    // Add a document
    void addDocument(const std::string& name, int id, int license_limit);

    // Add a patron
    void addPatron(int patronID);

    // Search for a document by name
    int search(const std::string& name);

    // Borrow a document
    bool borrowDocument(int docid, int patronID);

    // Return a document
    void returnDocument(int docid, int patronID);

private:
    struct Document {
        std::string name;
        int license_limit;
        int currentlyBorrowed;
    };

    std::unordered_map<std::string, int> docNameToID; // Map from document name to ID
    std::unordered_map<int, Document> documents; // Map from document ID to Document details
    std::unordered_set<int> patrons; // Set of registered patrons
    std::unordered_map<int, std::unordered_set<int>> borrowedDocs; // Map from document ID to set of patron IDs
};

#endif // DOCUMENT_MANAGER_H
