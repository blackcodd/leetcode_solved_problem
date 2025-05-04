class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int>mp;
        for(auto it:dominoes){
           if(it[0]>it[1]) {
            swap(it[0],it[1]);
           }
            mp[{it[0],it[1]}]++;
        }
        int ans=0;
        for(auto it:mp){
            if(it.second>1){
                ans+=(it.second*(it.second-1))/2;

            }
        }
        return ans;
        
    }
};