class Solution {
    private:
    bool f(vector<int>&candies,long long k,int div){
        int n= candies.size();
        if(div==0) return false;
         
          long long pile=0;
          for(int i=0;i<n;i++) {
            pile+=(candies[i]/div);
          }
          if(pile<k) return false;
          return true;

    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int mn=*max_element(candies.begin(),candies.end());
        int l=1,r=mn;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(f(candies,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        return ans;
        
    }
};