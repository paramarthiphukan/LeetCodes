class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
     unordered_map<int,int> map;
        vector<int> ans;
        int n=nums.size();
        
        for(int i=0; i<n; i++)
        {
            map[nums[i]]++;
        }
        
        for(auto it=map.begin(); it!=map.end(); it++)
        {
            
            if(it->second>(n/3)) 
                ans.push_back(it->first);
        }
        
        return ans;
    }
};