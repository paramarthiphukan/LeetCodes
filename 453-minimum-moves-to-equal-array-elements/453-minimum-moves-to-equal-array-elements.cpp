class Solution {
public:
   int minMoves(vector<int>& nums) 
   {
        int sum = 0, mini = INT_MAX;
        for(int i = 0; i < nums.size(); i++) 
        {
            if(mini > nums[i])
            {
                mini = nums[i];
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            sum += (nums[i] - mini);
        }
        return sum;
    }
};