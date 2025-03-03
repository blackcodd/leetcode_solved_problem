class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool>dp(n);
        for(int i=0;i<n;i++){
            for(auto it:wordDict){
                if(it.size()-1>i) continue;
                if(i==it.length()-1 || dp[i-it.length()]){
                    if(s.substr(i-it.length()+1,it.length())==it){
                        dp[i]=true;
                        break;

                    }
                }
            }
        }
        return dp[s.length()-1];
    }
};