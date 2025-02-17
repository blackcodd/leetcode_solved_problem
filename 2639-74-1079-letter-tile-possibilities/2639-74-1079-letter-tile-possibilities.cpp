// class Solution {
//     private:
//     unordered_map<string ,int>map;
//     string subset (string &s,int ind,string &ans){
//         if(ind==s.size()) return ans ;
//            ans+=s[ind]+subset(s,ind+1,ans);
//            map[ans]++;
//            ans.erase(ind,1);
//         }
//     void back_track(string &s,int i,int j){
//         if(i==j){
//             map[s]++;
//             subset(s, 0,"");
//         }
//         else {
//             for(int l=i;l<=j;l++){
//                 swap(s[i],s[l]);
//                 if(map[s]==0)
//                 back_track(s,i+1,j);
//                 swap(s[i],s[l]);
//             }
//         }
//     }
// public:
//     int numTilePossibilities(string tiles) {
//         back_track(tiles,0,tiles.size()-1);
//         for(auto it:map){
//             cout<<it.first<<" "<<it.second<<endl;
//         }
//         return 0;
        
//     }
// };
class Solution {
private:
    unordered_set<string> uniqueSequences;  // To store unique sequences

    void backtrack(string &tiles, vector<bool> &used, string current) {
        if (!current.empty()) {
            uniqueSequences.insert(current);
        }
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            backtrack(tiles, used, current + tiles[i]);
            used[i] = false;
        }
    }

public:
    int numTilePossibilities(string tiles) {
        vector<bool> used(tiles.size(), false);
        backtrack(tiles, used, "");
        return uniqueSequences.size();
    }
};
