class Solution {
public:
    bool canCross(vector<int>& stones) 
    {
    int n = stones.size();
    map<int, int> mp;
    
    for(int i = 0; i < n; i++)
        mp[stones[i]] = i;

    map<pair<int, int>, bool> dp;
    return helper(stones, mp, 0, 0, dp);
}

bool helper(vector<int> &stones, map<int, int> &mp, int i, int jump, map<pair<int, int>, bool> &dp)
{
    if(i == stones.size() - 1)
        return true;
    
    if(dp.find({i, jump}) != dp.end())
        return dp[{i, jump}];
    
    for(int k = -1; k <= 1; k++)
        if(jump + k > 0)
        {
            int new_pos = stones[i] + jump + k;

            if(mp.find(new_pos) != mp.end() && helper(stones, mp, mp[new_pos], jump + k, dp))
                return dp[{i, jump}] = true;
        }
    
    return dp[{i, jump}] = false;
}
};