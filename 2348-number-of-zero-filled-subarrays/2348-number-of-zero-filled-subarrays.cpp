class Solution
{
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
         int cnt = 0;
        long long res = 0;
        for(int num: nums) 
        {
            if(num == 0) 
            {
                cnt++;
                res += cnt;
            }
            else 
            {
                cnt = 0;
            }
        }
        return res;
    }
};

    