class Solution {
public:
    int countTriples(int n) {
        int ans=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                double sq=sqrt(i*i+j*j);
                if((i*i + j*j)<=n*n && (sq-int(sq))==0){
                    ans++;
                }

            }
        }
        return ans;
        
    }
};