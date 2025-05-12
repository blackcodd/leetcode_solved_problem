class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(),digits.end());
        int n=digits.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(digits[i]==0) continue;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && i!=k){
                   int it=  digits[i]*100+digits[j]*10+digits[k];
                   if(!(it&1)){
                    if(mp.count(it)==0){
                    ans.push_back(it);
                    mp[it]++;
                    }

                   }
                 }

                }
            }
        }
        return ans;
        
    }
};