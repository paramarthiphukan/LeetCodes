class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        if(k==0)
		return false;
		multiset<long> window;
        for(int i=0;i<nums.size();i++)
		{
		if(i>k)
		window.erase(nums[i-k-1]);
		auto it=window.lower_bound((long)nums[i]-(long)t);
		if(it!=window.end() && *it<=(long)nums[i]+(long)t)
		return true;
		window.insert(nums[i]);
		}
		return false;
	}
};