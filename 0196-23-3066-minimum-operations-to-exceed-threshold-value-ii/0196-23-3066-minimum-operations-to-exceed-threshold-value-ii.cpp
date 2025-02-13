class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
       priority_queue<long long ,vector<long long>,greater<long long>>pq;
       for(auto it:nums){
        pq.push(it);
       }
       int cnt=0;
       while(pq.top()<k){
        long long a=pq.top();
        pq.pop();
        long long  b=pq.top();
        pq.pop();
           long long temp=a*2LL+b;
        pq.push(temp);
        ++cnt;
       }
     return cnt;


    }
};