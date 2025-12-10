class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        // if any element (except index 0) is <= complexity[0], answer is 0
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) return 0;
        }

        // (n-1)! % MOD
        if (n <= 1) return 1;               // 0! or 1! -> 1
        long long ans = 1;
        for (int i = 2; i <= n - 1; ++i) {
            ans = (ans * i) % MOD;         // keep multiplication in 64-bit
        }
        return static_cast<int>(ans);
    }
};
