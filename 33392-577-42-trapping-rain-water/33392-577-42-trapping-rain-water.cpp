
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>v1(n),v2(n);
        v1[0]=height[0];
        for(int i=1;i<n;i++){
            v1[i]=max(v1[i-1],height[i]);
        }
        v2[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            v2[i]=max(v2[i+1],height[i]);

        }
        int ans=0;
        for(int i=0;i<n;i++){
            int mn=min(v1[i],v2[i]);
            if(mn>height[i]){
                ans+=mn-height[i];
            }

        }
        return ans;
      
        
       

        
    }
};