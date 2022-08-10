class Solution 
{
public:
     set<vector<int>> s;
    void util(vector<int>& nums,int i, vector<int>& k)
    {
        if(i==nums.size())
        {
            s.insert(k);
            return;
        }
        vector<int> a=k;
        util(nums,i+1,a);
        a.push_back(nums[i]);
        util(nums,i+1,a);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> a;
        sort(nums.begin(),nums.end());
        util(nums,0,a);
        vector<vector<int>> k;
        for(auto t:s)
         k.push_back(t);
        return k;
    }
};