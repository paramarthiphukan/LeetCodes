class Solution {
private:
	vector<int> adj[100001];
	int ans;
	int dfs(string& s, int node) {
		int maxi = 0, sMaxi = 0;
		for (auto &e : adj[node]) {
			int cur = dfs(s, e);
			if (s[node] != s[e]) {
				sMaxi = max(cur, sMaxi);
				if (sMaxi > maxi) swap(sMaxi, maxi);
			}
		}
		ans = max(ans, maxi + sMaxi + 1);
		return maxi + 1;
	}
public:
	int longestPath(vector<int>& a, string s) {
		int n = s.size();
		for (int i = 1; i < n; ++i)
			adj[a[i]].push_back(i);
		dfs(s, 0);
		return ans;
	}
};