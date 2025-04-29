class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        long long ans=0;
        int start=0;
        int inwin=0;
        for(int end=0;end<nums.size();end++){
            if(nums[end]==mx) inwin++;
            while(inwin==k){
                if(nums[start]==mx){
                    inwin--;
                }
                start++;
            }
            ans+=start;


        }
        return ans;

       
        
    }
};