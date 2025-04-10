
class Solution {
    long long f(string m,string s, int lim){
        if(m.size()<s.size()) return 0;
        if(m.size()==s.size()){
            if(m<s) return 0;
            else return 1;
        }
        int last=m.size()-s.size();
        long long cnt=0;
        for(int i=0;i<last;i++){
            if((m[i]-'0')>lim) { cnt+=pow(lim+1,last-i); return cnt;}
            cnt+=(long) (m[i]-'0')*(long) pow(lim+1,last-i-1);

        }
        string ss=m.substr(m.length()-s.length(),s.length());
        if(ss>=s) cnt++;
        return cnt;



    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string st=to_string(start-1);
        string e=to_string(finish);
        return f(e,s,limit)-f(st,s,limit);
        
    }
};
