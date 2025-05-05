class Solution {
    private:
    int M=1e9+7;
   int  f(int n,vector<int>dp){
    dp[1]=1;
    if(n>1)
    dp[2]=2;
    if(n>2)
    dp[3]=5;

    for(int i=4;i<=n;i++){
        dp[i]=((2%M*(dp[i-1]%M))%M+dp[i-3]%M)%M;

    }
    return dp[n];
        
    }

public:

    int numTilings(int n) {
        
         vector<int>dp(n+1,0);
        return f(n,dp);

        
    }
};