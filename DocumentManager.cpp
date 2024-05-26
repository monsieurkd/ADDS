#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

class DocumentManager {
public:
    // Add a document
    void addDocument(const std::string& name, int id, int license_limit) {
        if (docNameToID.find(name) != docNameToID.end()) {
            std::cerr << "Document with this name already exists." << std::endl;
            return;
        }
        docNameToID[name] = id;
        documents[id] = {name, license_limit, 0};
    }

    // Add a patron
    void addPatron(int patronID) {
        patrons.insert(patronID);
    }

    // Search for a document by name
    int search(const std::string& name) {
        auto it = docNameToID.find(name);
        if (it != docNameToID.end()) {
            return it->second;
        }
        return 0; // Document not found
    }

    // Borrow a document
    bool borrowDocument(int docid, int patronID) {
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

    // Return a document
    void returnDocument(int docid, int patronID) {
        auto docIt = documents.find(docid);
        if (docIt == documents.end()) {
            return; // Document not found
        }
        Document& doc = docIt->second;
        if (borrowedDocs[docid].erase(patronID)) {
            doc.currentlyBorrowed--;
        }
    }

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

int main() {
    DocumentManager dm;
    dm.addPatron(1);
    dm.addDocument("C++ Programming", 101, 2);
    
    std::cout << "Searching for 'C++ Programming': " << dm.search("C++ Programming") << std::endl;
    
    if (dm.borrowDocument(101, 1)) {
        std::cout << "Document borrowed successfully." << std::endl;
    } else {
        std::cout << "Failed to borrow document." << std::endl;
    }
    
    dm.returnDocument(101, 1);
    std::cout << "Document returned." << std::endl;
    
    return 0;
}
