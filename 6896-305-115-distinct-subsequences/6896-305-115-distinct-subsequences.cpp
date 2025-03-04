class Solution {
    int f(string &s, string &t, int n, int m,vector<vector<int>>&dp) {
        if (m == 0) return dp[n][m]= 1; // If t is empty, there is exactly one subsequence that matches: the empty subsequence.
        if (n == 0) return dp[n][m]= 0; // If s is empty but t is not, no subsequence can be found.
        if(dp[n][m]!=-1) return dp[n][m];

        if (s[n - 1] == t[m - 1]) {
            return  dp[n][m]=f(s, t, n - 1, m - 1,dp) + f(s, t, n - 1, m,dp);
        }
        return dp[n][m]=f(s, t, n - 1, m,dp);
    }

public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        return f(s, t, s.size(), t.size(),dp);
    }
};
