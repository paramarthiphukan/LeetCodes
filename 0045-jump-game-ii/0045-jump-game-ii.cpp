class Solution
{
public:
    int jump(vector<int>& nums) 
    { 
        int res = 0; 
        int currReach = 0;
        int nextReach = 0;
        for (int i = 0; i < nums.size() - 1; i++) 
        {
            nextReach = max(nextReach, i + nums[i]);
            if (i == currReach) 
            {
                currReach = nextReach;
                nextReach = 0;
                res++;
            }
        }
        return res;
    }
};
        