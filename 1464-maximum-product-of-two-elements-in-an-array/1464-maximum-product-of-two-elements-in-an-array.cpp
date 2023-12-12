class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = max(nums[0],nums[1]);
        int smx = min(nums[0],nums[1]);
        for(int i = 2;i<n;i++){
            if(mx <= nums[i]){
                smx = mx;
                mx = nums[i];
            }else if(mx>nums[i] && smx<nums[i]){
                smx = nums[i];
            }
        }
        mx--;
        smx--;
        int ans = mx*smx;
        return ans;
    }
};