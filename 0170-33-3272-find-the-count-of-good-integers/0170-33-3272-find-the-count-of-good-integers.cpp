#define ll long long 
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string>dic;
      ll m=(n-1)/2;
      ll base=pow(10,m);
      int sk=(n%2) ? 1:0;
      for(ll start=base; start<10*base;start++){
        string cu=to_string(start);
        string t=cu;
        if(sk) cu.pop_back();
        reverse(cu.begin(),cu.end());
        t+=cu;
        ll palint=stoll(t);
        if(palint%k==0){
            sort(t.begin(),t.end());
            dic.emplace(t);

        }
      }
      vector<ll>fact(n+1,1);
      ll ans=0LL;
      for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i;
      }
      for(auto s:dic){
        vector<int>cnt(10);
        for(auto it:s){
               cnt[it-'0']++;
        }
        ll tot=fact[n-1]*(n-cnt[0]);
        for(int x:cnt){
            tot/=fact[x];
        }
        ans+=tot;
      }
      return ans;

      }
      
    };

