class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int  n=nums1.size();
  int  m=nums2.size();
  //cout<<m<<" "<<n<<endl;
  int i=0,j=0;
  vector<int>v;

   while(1){
    if(i>=n) {v.push_back(nums2[j]),j++;}
    else if(j>=m){v.push_back(nums1[i]),i++;}
     else if(nums1[i]<=nums2[j]) {v.push_back(nums1[i]),i++;}
    else {v.push_back(nums2[j]),j++;}
    if(v.size()>((m+n)/2)) break;
    }
    //for(i=0;i<v.size();i++) cout<<v[i]<<" ";
    //cout<<endl;
    int ind=(m+n)/2;
    double ans;
    if((m+n)&1)  ans= (double) v[ind];
    else ans= (double)  (v[ind]+v[ind-1])/2;
   return ans;
        
    }
};
