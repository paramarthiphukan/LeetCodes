class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) 
    {
        vector<int> ans;
        int len = nums[0].length();
        for(auto it : queries)
        {
            vector<pair<string, int>> s(nums.size());
            for(int i=0; i<nums.size(); i++){
                s[i] = {nums[i].substr(len-it[1], it[1]), i};
            }
            sort(s.begin(), s.end());
            ans.push_back(s[it[0]-1].second);
        }
        return ans;
    }
};