class Solution {
    private:
    long long  dp_f(int ind,vector<vector<int>>&qustions,int n,vector<long long >&dp){
        if(ind>=n) return 0LL;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=max( dp_f(ind+qustions[ind][1]+1,qustions,n,dp)+qustions[ind][0],dp_f(ind+1,qustions,n,dp));

    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long >dp(n,-1);
        return dp_f(0,questions,n,dp);
        
    }
};