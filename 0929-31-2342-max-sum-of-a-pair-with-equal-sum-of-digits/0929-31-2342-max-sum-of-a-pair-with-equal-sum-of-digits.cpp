class Solution {
    private:
     int dig_sum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
     }
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int ,stack<int>>mp;
        for(int i=0;i<n;i++){
            cout<<dig_sum(nums[i])<<" ";
            mp[dig_sum(nums[i])].push(i);
        }
        int ans=-1;
        for(int i=n-1;i>=0;i--){
            int di=dig_sum(nums[i]);
            if(mp[di].size()>1){
                mp[di].pop();
                int ind=mp[di].top();
                ans=max(ans,nums[i]+nums[ind]);
            }
        }
        return ans;

        
    }
};