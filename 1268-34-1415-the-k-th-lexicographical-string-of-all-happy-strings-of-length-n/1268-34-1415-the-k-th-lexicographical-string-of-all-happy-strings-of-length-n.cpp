class Solution {
    private:
    void f(int n,string currs ,vector<string>&v){
        if(currs.size()==n) {v.push_back(currs); return ;};
      
         for(char it='a'; it <'d';it++){
           
            if( currs.size()>0 && currs[currs.size()-1]==it){
               continue;
            }
             f(n,currs+it,v);
         }
    }
public:
    string getHappyString(int n, int k) {
        string s;
        vector<string>v;
        f(n,s,v);
        if(v.size()<k) return "";
        sort(v.begin(),v.end());
        return v[k-1];

        
    }
};