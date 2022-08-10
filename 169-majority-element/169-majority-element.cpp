class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int count = 0, majority;
        for(auto num : nums)
        {
            if(count==0) majority = num;
            if(majority == num) count++;
            else count--;
        }
        return majority;
    }
};