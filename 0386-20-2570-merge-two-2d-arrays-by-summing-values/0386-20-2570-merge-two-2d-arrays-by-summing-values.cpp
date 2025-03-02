class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
       
        int k=0;
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>vec;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i][0]==nums2[j][0]){
               vec.push_back( {nums1[i][0] ,nums1[i][1]+nums2[j][1]});
                i++;
                j++;
                
            }
            else if(nums1[i][0]<nums2[j][0]){
                 vec.push_back( {nums1[i][0] ,nums1[i][1]});
                i++;
            

            }
            else {
                vec.push_back( {nums2[j][0] ,nums2[j][1]});
                j++;
                
            }
        }
        while(i<n){
            vec.push_back( {nums1[i][0] ,nums1[i][1]});
                i++;
              

        }
        while(j<m){
             vec.push_back( {nums2[j][0] ,nums2[j][1]});
                j++;
              

        }
        return vec;
        
    }
};