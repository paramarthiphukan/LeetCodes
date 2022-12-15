class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.length();
        int n2 = text2.length();
        int dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                char a = text1[i - 1];
                char b = text2[j - 1];
                if (a == b)
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n1][n2];
    }
};