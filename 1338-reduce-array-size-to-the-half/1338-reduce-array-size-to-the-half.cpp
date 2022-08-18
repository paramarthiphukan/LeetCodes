class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        int n = arr.size();
		int ct = 0;
		priority_queue<pair<int, int>> MAX_HEAP;
		unordered_map<int, int> m;
		for (auto &e : arr) m[e]++;
		for (auto &e : m) MAX_HEAP.push({e.second, e.first});
        n/=2;
		while (!MAX_HEAP.empty() && n > 0) 
        {
			auto node = MAX_HEAP.top();
			MAX_HEAP.pop();
			ct++;
			n -= node.first;
		}
		return ct;
    }
};