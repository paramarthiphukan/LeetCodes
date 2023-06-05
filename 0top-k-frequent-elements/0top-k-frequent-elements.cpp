class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (const auto& it: nums) {
            --frequency[it];
        }
        vector<pair<int, int>> v;
        for (const auto& [key, val]: frequency) {
            v.emplace_back(val, key);
        }
        nth_element(v.begin(), v.begin() + k, v.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(v[i].second);
        }
        return ans; 
    }
};