class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[] ( vector<int>&a,vector<int>&b){  return a[1]<b[1];});
        int n=pairs.size();
        vector<int>v(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    if(v[j]+1 >v[i]){
                        v[i]=v[j]+1;
                    }                 
                }
            }
        }
        int ans=*max_element(v.begin(),v.end());
        return ans;

      


        
    }
};