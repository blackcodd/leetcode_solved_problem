class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int >lmax(n);
        vector<int>rmax(n);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>l){
                lmax[i]=nums[i-1];
                l=nums[i-1];
            }
            else lmax[i]=l;

        }
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>r){
                r=nums[i+1];
            }
            rmax[i]=r;
        }
        long long ans=0LL;
        for(int i=1;i<n-1;i++){
             ans=max(ans,(lmax[i]-nums[i])*1LL*rmax[i] );
        }
        return ans;

        
    }
};