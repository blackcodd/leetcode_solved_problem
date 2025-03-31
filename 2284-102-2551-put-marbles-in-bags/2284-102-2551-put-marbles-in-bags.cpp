class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>p(n-1,0);
        for(int i=1;i<n;i++){
            p[i-1]=weights[i-1]+weights[i];
        }
        sort(p.begin(),p.end());
        long long ans=0;
        for(int i=0;i<k-1;i++){
            ans+=p[n-2-i]-p[i];
        }
        return ans;
        
    }
};