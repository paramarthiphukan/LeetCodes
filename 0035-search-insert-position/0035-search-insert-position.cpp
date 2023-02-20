class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
       int i=0,n=nums.size()-1,mid=(i+n)/2;
        while(i<=n)
        {
            if(nums[mid]<target)
            {
                i=mid+1;
            } 
            else if(nums[mid]>target)
            {
                n=mid-1;
            }
            else
            {
                return mid;
            }
            mid = (i+n)/2;
        }
        return i;
    
    }
};