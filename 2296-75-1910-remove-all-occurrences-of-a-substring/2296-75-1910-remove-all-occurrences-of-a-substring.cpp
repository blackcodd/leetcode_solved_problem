class Solution {
public:
    string removeOccurrences(string s, string part) {
         int ind = s.find(part);
        while (ind != string::npos) {
            s.erase(ind, part.size());
            ind = s.find(part);
        }
        return s;
        
    }
};