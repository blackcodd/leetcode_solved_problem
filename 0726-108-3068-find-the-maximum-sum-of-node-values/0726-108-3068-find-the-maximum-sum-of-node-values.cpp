class Solution {
private:
 long long f( int index,vector<int>&nums , int k, int iseven,vector<vector<long long>>&v){
    if(index==nums.size()){
        return  iseven==1? 0:INT_MIN;
    }
     if(v[index][iseven]!=-1) return v[index][iseven];
    long long xordone=(nums[index]^k) + f(index+1,nums,k,iseven^1,v);
    long long noxor=nums[index]+f(index+1,nums,k,iseven,v);
    return  v[index][iseven] = max(xordone,noxor);
 }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<long long >>dp(n, vector<long long>(2,-1));
        return f(0,nums,k,1,dp);
        
    }
};