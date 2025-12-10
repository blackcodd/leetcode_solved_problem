class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> total_cnt;
        for (int x : nums) total_cnt[x]++;

        unordered_map<int,int> left_freq_map;
        int ans = 0;
        const int M = 1e9 + 7;

        for (int x : nums) {

            int target = 2*x;

            int left_freq = left_freq_map[target];
            if(target==0 && left_freq>0) left_freq--;
            
            int right_freq = total_cnt[target] - left_freq;
            if(target==0 && right_freq>0) right_freq--;

            // multiply safely
            long long mul = 1LL * left_freq * right_freq;
            mul %= M;

            ans = (ans + mul) % M;

            left_freq_map[x]++;
        }

        return ans;
    }
};
