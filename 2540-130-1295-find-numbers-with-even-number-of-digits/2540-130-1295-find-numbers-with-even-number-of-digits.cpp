class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(auto it:nums){
            int x=it;
            int cnt=0;
            while(x){
                ++cnt;
                x/=10;
            }
            if(cnt&1){

            }
            else ans++;

        }
        return ans;

        
    }
};