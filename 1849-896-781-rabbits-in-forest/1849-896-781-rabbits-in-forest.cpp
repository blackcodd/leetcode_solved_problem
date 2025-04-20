class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (auto it : answers) {
            mp[it]++;
        }

        for (auto& [x, count] : mp) {
            int group_size = x + 1;
            int groups = (count + x) / group_size;  
            ans += groups * group_size;
        }

        return ans;
    }
};
