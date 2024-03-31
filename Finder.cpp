#include "Finder.h"

    using namespace std;

    vector<int> Finder::findSubstrings(string s1, string s2) {

        vector<int> result;
        int flag = 0;
        int last_index_found= 0;
        for(size_t i = 1; i <= s2.size(); i++) {
            size_t found = s1.find(s2.substr(0, i), last_index_found);
            last_index_found = found;
            if (found != string::npos && flag == 0) {
                result.push_back(found);
            } else {
                result.push_back(-1);
                flag = 1;
                
            }
        }
        return result;
    }

   