class Solution {
public:
       void solve(int ind,vector<int>& nums,vector<int> &ds,set<vector<int>> &st)
       {
        if(ds.size()>=2)
        {
            st.insert(ds);
        }
        
        for(int i=ind;i<nums.size();i++)
        {
            if(ds.size()==0 || ds[ds.size()-1]<=nums[i])
            {
                ds.push_back(nums[i]);
                solve(i+1,nums,ds,st);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<int> ds;
        set<vector<int>> st;
        solve(0,nums,ds,st);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};