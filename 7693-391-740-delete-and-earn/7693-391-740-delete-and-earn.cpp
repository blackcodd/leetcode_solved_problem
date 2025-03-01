class Solution {
    private:
 
public:
    int deleteAndEarn(vector<int>& nums) {
       vector<int>sum(10001,0);
       int mxv=0;
       for(auto it:nums){
        sum[it]+=it;
        mxv=max(mxv,it);

       }
        vector<int>dp(mxv+1,0);
        dp[0]=sum[0];
        dp[1]=sum[1];
        for(int i=2;i<=mxv;i++){
            dp[i]=max(dp[i-1],dp[i-2]+sum[i]);
        }

         return dp[mxv];
        
       
    }
};