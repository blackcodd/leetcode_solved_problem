class Solution
{
public:
    int minCapability(vector<int> &nums, int k)
    {
        int mn = 1e9 + 1;
        int mx = 0;
        for (auto it : nums)
        {
            mn = min(it, mn);
            mx = max(it, mx);
        }
       
        int l = mn;
        int r = mx;
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            vector<bool> rob(nums.size() + 1,false);
            int cnt = 0;
            
            for (int i = 0; i < nums.size();i++)
            {
                if (i == 0)
                {
                    if (nums[i] <= mid)
                    {
                        ++cnt;
                        rob[i] = true;
                    }
                }
                    else
                    {
                        if (nums[i] <= mid && rob[i - 1] == false)
                        {
                            ++cnt;
                            rob[i] = true;
                        }
                    }
                
            }
         
                if (cnt < k)
                {
                    l = mid + 1;
                }
                else
                {
                    ans = mid;
                    r = mid - 1;
                }
            
           
        }
         return ans;
    }
};