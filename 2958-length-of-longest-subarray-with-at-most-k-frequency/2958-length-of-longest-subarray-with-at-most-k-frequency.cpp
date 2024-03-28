class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int len,maxlen=0,left=0,right=0;
        unordered_map<int,int> mpp;
        while(right<n){
            mpp[nums[right]]++;
            while(mpp[nums[right]]>k && left<=right){
                mpp[nums[left]]--;
                left++;
            }

            len=right-left+1;
            maxlen=max(maxlen,len);
            right++;
        }

        return maxlen;
    }
};