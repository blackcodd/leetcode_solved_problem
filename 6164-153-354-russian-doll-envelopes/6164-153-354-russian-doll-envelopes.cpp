class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;

        // Step 1: Sort by width, then by height in descending order if widths are same
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);
        });

        // Step 2: Find LIS based on heights
        vector<int> lis;
        for (auto& env : envelopes) {
            int h = env[1];
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) {
                lis.push_back(h);
            } else {
                *it = h;
            }
        }
        return lis.size();
    }
};
