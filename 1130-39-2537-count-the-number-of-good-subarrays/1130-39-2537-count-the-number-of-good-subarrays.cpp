class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, long long> freq;
        long long count = 0, res = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            count += freq[nums[right]];
            freq[nums[right]]++;

            while (count >= k) {
                res += nums.size() - right;
                freq[nums[left]]--;
                count -= freq[nums[left]];
                left++;
            }
        }

        return res;
    }
};
