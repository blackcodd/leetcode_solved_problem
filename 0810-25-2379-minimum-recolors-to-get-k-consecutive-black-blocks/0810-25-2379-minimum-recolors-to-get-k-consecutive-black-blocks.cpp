class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int op=INT_MAX,BL=INT_MAX;
        for(int i=0;i<n;i++){
            int w=0;
            for(int j=i;j<n;j++){
                if(blocks[j]=='W') w++;
                if(j-i+1>=k){
                    op=min(op,w);
                }

            }
            
           
        }
        return op;
        
    }
};