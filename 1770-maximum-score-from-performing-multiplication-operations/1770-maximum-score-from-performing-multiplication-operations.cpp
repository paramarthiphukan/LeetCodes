class Solution 
{
private:
    vector<vector<int>> dp;
	int f(int s ,int i, vector<int>& a, vector<int>& m)
    {
		if (i >= m.size()) return 0;
        
        if(dp[s][i] != INT_MAX) return dp[s][i];
        int e = a.size() - 1 - (i - s);
		int ans1 = a[s] * m[i] + f(s + 1, i + 1, a, m);
		int ans2 = a[e] * m[i] + f(s, i + 1, a, m);
		return dp[s][i] = max(ans1, ans2);
	}
public:
	int maximumScore(vector<int>& a, vector<int>& m) 
    {
        dp.assign(m.size(), vector<int>(m.size(), INT_MAX));
		return f(0, 0, a, m);
	}
};