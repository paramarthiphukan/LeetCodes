class Solution 
{
public:
      long long countBadPairs(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i) nums[i] = nums[i] - i;
		unordered_map<long long, long long> m;
		for (auto &e : nums) m[e]++;
		long long ct = 0;
		long long x = nums.size();
		ct = (x * (x - 1)) >> 1;
		for (auto &e : m) {
			if (e.second > 1) ct -= (e.second * (e.second - 1)) >> 1;
		}
		return ct;
	}
};