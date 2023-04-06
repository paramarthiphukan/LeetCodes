class Solution {
public:
    bool checker(int maxi,vector<long> nums,int n)
    {   
        if(nums[0] > maxi)
            return false;
        for(int i = n - 1; i > 0 ; i--)
        {
            if(nums[i] <= maxi)
                continue;
            long diff = nums[i] - maxi;
            nums[i - 1] += diff;
        }
        if(nums[0] > maxi)  
            return false;
        return true;
    }
    int minimizeArrayValue(vector<int>& nums)
    {
        int n = nums.size(),ll = 0,ul = 1e9,mid = 0,ans = 0;
        vector<long> vec(nums.begin(),nums.end());
        while(ll <= ul)
        {
            mid = (ll + ul) >> 1;
            if(checker(mid,vec,n))
            {
                ul = mid - 1;
                ans = mid;
            }
            else
                ll = mid + 1;
        }
        return ans;
    }
};