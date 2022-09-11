class Solution 
{
public:
       int N = 1e9 + 7;
	static bool cmp(pair<int, int> &a , pair<int, int> &b) 
    {
		return a.first > b.first;
	}
	int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) 
    {
		vector<pair<int, int>> v;
		for (int i = 0; i < n; ++i) v.push_back({e[i], s[i]});
		sort(v.begin(), v.end(), cmp);

		long long sum = 0, ans = INT_MIN;
		priority_queue < int, vector<int>, greater<int>> minh;
		for (int i = 0 ; i < n; ++i) 
        {

			sum += v[i].second;
			minh.emplace(v[i].second);

			if (minh.size() > k)
            {
				sum -= minh.top(); minh.pop();
			}
			ans = max(ans, sum * v[i].first);
		}
		return (ans) % N;
	}
};