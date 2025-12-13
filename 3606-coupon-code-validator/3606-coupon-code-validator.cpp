class Solution {
private:
    bool valid(string s) {
        if (s.size() == 0) return false;

        for (char x : s) {
            if ((x >= 'a' && x <= 'z') ||
                (x >= 'A' && x <= 'Z') ||
                (x >= '0' && x <= '9') ||
                x == '_') {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        int n = code.size();
        vector<pair<string, string>> v;

        map<string, bool> m;
        m["electronics"] = true;
        m["grocery"] = true;
        m["pharmacy"] = true;
        m["restaurant"] = true;

        for (int i = 0; i < n; i++) {
            if (isActive[i] && valid(code[i]) && m[businessLine[i]]) {
                v.push_back({code[i], businessLine[i]});
            }
        }

        sort(v.begin(), v.end(), [&](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> ans;
        for (auto &it : v) {
            ans.push_back(it.first);
        }
        return ans;
    }
};
