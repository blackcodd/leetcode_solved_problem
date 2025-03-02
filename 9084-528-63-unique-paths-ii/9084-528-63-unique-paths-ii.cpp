class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obg) {
        int n=obg.size();
        int m=obg[0].size();
        
        obg[0][0]=obg[0][0]^1^0;
        for(int i=1;i<n;i++){
            if(obg[i][0]==1) obg[i][0]=0; 
            else obg[i][0]=obg[i-1][0];
        }
         for(int i=1;i<m;i++){
            if(obg[0][i]==1) obg[0][i]=0; 
            else obg[0][i]=obg[0][i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obg[i][j]==1){
                    obg[i][j]=0;
                }
                else{
                    obg[i][j]=obg[i-1][j]+obg[i][j-1];
                }
            }
        }
        return obg[n-1][m-1];
        
    }
};