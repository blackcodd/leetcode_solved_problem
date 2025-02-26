class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = 0, min_sum = 0, sum_max = 0, sum_min = 0;
        
        for (int num : nums) {
            sum_max = max(num, sum_max + num);
            sum_min = min(num, sum_min + num);
            max_sum = max(max_sum, sum_max);
            min_sum = min(min_sum, sum_min);
        }
        
        return max(abs(max_sum), abs(min_sum));
    }
};
