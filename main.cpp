#include <iostream>
#include "Autocomplete.h"
using namespace std;

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
