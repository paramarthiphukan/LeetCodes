class Solution {
public:
      int countVowelPermutation(int n)
      {
        vector<vector<long long>>dp(n, vector<long long>(5, 1));
        int MOD = 1000000007;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][1]; 
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD; 
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4]) % MOD; 
            dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % MOD; 
            dp[i][4] = dp[i - 1][0] ;
        }
        long long sum = 0;
        for (int i = 0; i < 5; i++) sum  = (sum + dp[n - 1][i]) % MOD;
        return sum;
    }
};