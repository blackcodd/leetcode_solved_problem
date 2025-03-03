class Solution {
    private:
    int f(string s1,string s2,int m, int n,vector<vector<int>>&dp){
    
    if(m==0) return n;
    if(n==0) return m;
    if(dp[m-1][n-1]!=-1) return dp[m-1][n-1];
    if(s1[m-1]==s2[n-1]) {
        return  dp[m-1][n-1]=f(s1,s2,m-1,n-1,dp);
    }
    return  dp[m-1][n-1]=1 +min({f(s1,s2,m-1,n,dp),f(s1,s2,m,n-1,dp),f(s1,s2,m-1,n-1,dp)});

    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(word1,word2,word1.size(),word2.size(),dp);
    }
};