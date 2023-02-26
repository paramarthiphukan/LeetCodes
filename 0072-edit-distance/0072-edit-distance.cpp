class Solution 
{
public:
      int minDistance(string s, string t) 
      {
		int n = s.size(), m = t.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i <= n; ++i) dp[i][0] = i;
		for (int j = 0; j <= m; ++j) dp[0][j] = j;

		  for (int i = 1; i <= n; ++i) 
        {
			for (int j = 1; j <= m; ++j)
            {
				if (s[i - 1] == t[j - 1]) dp[i][j] = 0 + dp[i - 1][j - 1];
				else {
					int insert = 1 + dp[i][j - 1];
					int dlete = 1 + dp[i - 1][j];
					int replace = 1 + dp[i - 1][j - 1];
					dp[i][j] = min(insert, min(dlete, replace));
				}
			}
		}
		return dp[n][m];
	}
};