class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int  ma=0,mn=1e6+7;
        for(auto it:ranks){
            ma=max(it,ma);
            mn=min(it,mn);
        }
        long long l=1;
        long long r= (long long)mn*cars*cars;
        long long ans;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long  carsn=0;
            for(int i=0;i<ranks.size();i++){
                carsn+=(long long)sqrt(mid/ranks[i]);

            }
            if(carsn<cars) {
                l=mid+1;
            }
            else {
                ans=r;
                r=mid-1;
            }


        }
        return r+1;
        
    }
};