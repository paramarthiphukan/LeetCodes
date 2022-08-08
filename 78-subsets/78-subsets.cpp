class Solution {
public:
      vector<vector<int>>ans;
      void ss(const vector<int>& nums,int j,vector<int>&v)
      {
        ans.push_back(v);
        if (j>nums.size()) return;
        for (int i=j;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            ss(nums,i+1,v);
            v.pop_back();        
}
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int>v;
        ss(nums,0,v);
        return ans;
    }
};