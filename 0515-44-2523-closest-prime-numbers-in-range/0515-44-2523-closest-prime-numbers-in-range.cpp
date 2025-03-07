class Solution {
    private:
     vector<int>f(int left,int right)
     {
        
       
        vector<bool>v(right+1,true);
       
        for(int i=2;i*i<=right;i++){
            if(v[i]==true){
                for(int j=i*i;j<=right;j+=i){
                    v[j]=false;
                }

            }
        }
        vector<int>ans;
        if(left==1) left++;
       for(int i=left;i<=right;i++){
        if(v[i]){
             ans.push_back(i);     
        }

       }
       int n=ans.size();
       int a=-1,b=-1;
       int dis=INT_MAX;
       for(int i=0;i<n-1;i++){
          
            if(ans[i+1]-ans[i]<dis){
                a=ans[i];
                b=ans[i+1];
                dis=ans[i+1]-ans[i];
            }
     
            
       }
       return {a,b};
      
        
      
    }
public:
    vector<int> closestPrimes(int left, int right) {
        
         return f(left,right);
    }
};