class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long  x=1;
        long long  mn=1,mx=1;
        for(auto it:differences){
          x+=it;
          mn=min(mn,x);
          mx=max(mx,x);
        }
        int ans=(upper-lower+1)-(mx-mn);
        cout<<ans<<endl;
        return  max(0,ans);

        
    }
};