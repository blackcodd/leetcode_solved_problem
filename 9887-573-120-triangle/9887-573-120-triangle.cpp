class Solution {
    
public:
    int minimumTotal(vector<vector<int>>&t) {
        int n=t.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        dp[0][0]=t[0][0];
        for(int j=1;j<n;j++){
            dp[j][0]=dp[j-1][0]+t[j][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                dp[i][j]=min(dp[i-1][j]+t[i][j] ,dp[i-1][j-1]+t[i][j]);

            }
        }
       int res=*min_element(dp[n-1].begin(),dp[n-1].end());
        return res;

        
    }
};