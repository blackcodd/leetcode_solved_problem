#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
       return a[0]<b[0];
        });
        priority_queue<int>hep;
        vector<int>delta(nums.size()+1,0);
        int op=0;
        for(int i=0,j=0;i<nums.size();i++){
            
            op+=delta[i];
            while(j<queries.size() && queries[j][0]==i){
                hep.push(queries[j][1]);
                ++j;
            }
            while(op<nums[i] && !hep.empty() && hep.top()>=i){
                op+=1;
                delta[hep.top()+1]-=1;
                hep.pop();
            }
            if(op<nums[i]) return -1;



           
        }
      return hep.size();

    }
};
