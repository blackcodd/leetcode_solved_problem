class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<int>st;
        int i;
        for(i=n-1;i>=0;i--){
            if(nums[i]<k) return -1;
            st.insert(nums[i]);
        }
        if(st.find(k)!=st.end()){
            return st.size()-1;
        }
        return st.size();
        
        
    }
};