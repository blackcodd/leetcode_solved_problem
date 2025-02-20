class Solution {
private:
 bool back(string s,int n,set<string>&st,string&result){
    if(s.size()==n){
        if(st.find(s)==st.end()){
            result=s;
            return true;

        }
        return false;
    }
    if(back(s+'1',n,st,result)) return true;
    return back(s+'0',n,st,result);

}
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        set<string>st;
        for(auto it:nums) st.insert(it);
        string result;
        bool ans=back("",n,st,result);
        
        return result;

        
    }
};