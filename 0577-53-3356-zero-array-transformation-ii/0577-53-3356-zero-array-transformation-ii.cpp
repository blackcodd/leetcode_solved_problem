class Solution {
private:
    bool f(vector<int>& nums, vector<vector<int>>& v, int max_ind, long long sum) {
        int n = nums.size();
        vector<long long> dif(n + 1, 0);
        
        
        for (int i = 0; i < max_ind; i++) {
            int l = v[i][0];
            int r = v[i][1];
            int x = v[i][2];
            dif[l] += x;
            dif[r + 1] -= x;
        }
        
        long long curr = 0;
        for (int i = 0; i < n; i++) {
            curr += dif[i];
            if(curr<nums[i])return false;
        }
        
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        long long sum = 0;
        for (int num : nums) sum += num;
        if(!f(nums,queries,n,sum)) return -1;

        int l = 0, r = n ;
        while (l <= r) {
            int mid =l+ ( r-l) / 2;
            if (f(nums, queries, mid, sum)) {
               
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
