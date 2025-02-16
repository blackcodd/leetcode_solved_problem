class Solution {
    bool F(vector<int>&a,int index,vector<bool>&used,int n){

        if(index==a.size()) return true ;
        if(a[index]!=0){
             return F(a,index+1,used,n);
        }
        for(int j=n;j>=1;j--){
            if(used[j]==true) continue;
            used[j]=true;
            a[index]=j;
            if(j==1){
                if( F(a,index+1,used,n)) return true;
            }
            else if(index+j < a.size() && a[index+j]==0){
                a[index+j]=j; 
               
            if(F(a,index+1,used,n)) return true;
            a[index+j]=0; 
            }
             a[index]=0;
             used[j]=false;
        }
        return false;

    }
    

public:
    vector<int> constructDistancedSequence(int n) {
        int sz=(n-1)*2+1;
        vector<int>ans(sz,0);
        vector<bool>used(n+1,false);
         if(F(ans,0,used,n))
         return ans;
         else return ans;
        
    }

};