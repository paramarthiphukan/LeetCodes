class Solution 
{
public:
    bool isPossible(vector<int>& nums, int m, int totSum) 
    {
        int noOfArr = 1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++) 
        {
            if(nums[i] > totSum) 
                return false;
            if(sum + nums[i] > totSum) 
            {
                noOfArr++;
                sum = nums[i];
            } 
            else 
            {
                sum += nums[i];
            }
            if(noOfArr > m) 
                return false;
        }   
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) 
    { 
        
        int n = nums.size();
        int left = 0;
        int right = 0;
        for(int i : nums) right += i;
        int mid;
        while(left <= right) 
        {
            mid = (left + right)/2;
            if(isPossible(nums, m, mid)) 
            { 
                right = mid-1;
            } 
            else 
            {
                left = mid+1;
            }
        }
        return left;
    }
};