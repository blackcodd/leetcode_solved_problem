class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>v1(max(n,m),0);
        vector<int>v2(max(n,m),0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) {
                    v1[i]=1;
                    v2[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v1[i]){
                    matrix[i][j]=0;
                }
                if(v2[j]){
                    matrix[i][j]=0;
                }
            }
        }

        
    }
};