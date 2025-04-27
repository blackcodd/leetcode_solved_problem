class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0;
        int ans=0;
        while(i+2<nums.size()){
            if((nums[i+2]+nums[i])*2==nums[i+1]) ++ans;
            i++;
        }
        return ans;
        
    }
};