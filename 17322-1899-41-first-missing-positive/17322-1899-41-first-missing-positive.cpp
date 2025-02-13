class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        int n=nums.size();
        int i=0;
        int f=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){ f=i;break;}
            else continue;
        }
        cout<<f<<endl;
        if(f==-1) return 1;
        
        if(nums[f]>1) return 1;
        for(int i=f+1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]!=nums[i-1]+1){
                return nums[i-1]+1;
            }

        }
        return nums[nums.size()-1]+1;

        
    }
};