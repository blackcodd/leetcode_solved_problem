class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int max_ele=0,m_f=0;
        vector<int>v(n,0);
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
             if(mp[nums[i]]>m_f)
             {
                m_f=mp[nums[i]];
                max_ele=nums[i];
             }
        }
        int cnt=0;
        int total=mp[max_ele];
        for(int i=0;i<n;i++){
            if(nums[i]==max_ele){
                cnt++;
            }
            v[i]=cnt;
            if(2*cnt>(i+1) && max(0,(total-cnt))*2>(n-i-1)){
                return i;
            }

        }
        return -1;


        
    }
};