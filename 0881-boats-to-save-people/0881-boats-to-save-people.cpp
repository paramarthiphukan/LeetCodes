class Solution 
{
public:
    int numRescueBoats(vector<int>& nums, int limit) 
    {
        sort(nums.begin(),nums.end(),greater<int>());
        int ans = 0;
        for(int i=0,j=nums.size()-1;i<=j;i++,j--)
        {
            if(nums[i] == limit)
            {
                j++;
            }
            else
            {
                if(nums[i] + nums[j] <= limit){
                }
                else
                {
                    j++;
                }
            }
			ans++;
        }
        return ans;
    }
};