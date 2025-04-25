class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> countMap;
        countMap[0] = 1; // For subarrays starting from index 0

        long long res = 0;
        int prefix = 0;

        for (int num : nums) {
            // If condition is met, increment prefix count
            if (num % modulo == k) {
                prefix++;
            }

            // Want prefix % modulo == target
            int mod = (prefix - k + modulo) % modulo;
            if (countMap.count(mod)) {
                res += countMap[mod];
            }

            // Record current prefix modulo count
            countMap[prefix % modulo]++;
        }

        return res;
    }
};
