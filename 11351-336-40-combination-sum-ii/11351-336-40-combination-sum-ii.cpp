 void back_trac(vector<vector<int>>&ans,vector<int>&can,vector<int>&an,int target,int i) {
         if(target==0) { ans.push_back(an); return;}
         for(int j=i;j<can.size()&& target>=can[j];j++){
            if(j==i || can[j]!=can[j-1]){
                an.push_back(can[j]);
                back_trac(ans,can,an,target-can[j],j+1);
                an.pop_back();
            }
         }

        



 }
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>an;
        sort(candidates.begin(),candidates.end());
        back_trac(ans,candidates,an,target,0);
        return  ans;
        
        
        
    }
};