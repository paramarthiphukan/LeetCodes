class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int maxend = 0;
        int maxsofar = INT_MIN;
        int minsofar = 0;
        int minsum = INT_MAX;
        int sum=0;
        bool allnegative = true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                allnegative = false;
            }
            else{
                maxsofar = max(maxsofar,nums[i]);
            }
        }
        
        if(allnegative)
        {
            return maxsofar;
        }
        for(int i=0;i<nums.size();i++)
        {
            //maximum subarray
            maxend = maxend + nums[i];
            maxsofar = max(maxsofar,maxend);
            if(maxend<0)
            {
                maxend = 0;
            }
            
            //minimum 
            minsofar = minsofar + nums[i];
            minsum = min(minsum,minsofar);
            
            if(minsofar > 0)
            {
                minsofar = 0;
            }
            
            sum+=nums[i];
        }
        return max(maxsofar,sum-minsum);
    }
};
    