class Solution {
    
public:
    int countDays(int days, vector<vector<int>>& meetings) {
             sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int n= meetings.size();
        int prev=0;
        int ans=0;
        
        for(auto it:meetings){
         //  cout<<it[0]<<" "<<it[1]<<endl;
            if(it[0]>prev){
                ans+=it[0]-prev-1;
              
                

            }
              prev= max(prev,it[1]);
        }
        ans+= days-prev;
        return ans;

    }
};