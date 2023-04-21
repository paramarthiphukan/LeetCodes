class Solution {
public:
    int dp[101][101][101];
    const int M = 1e9 + 7;
    int fn(int i, int p, int c, int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        p = min(p, minProfit);
        if(i >= group.size()) return c<= n && p >= minProfit;
        if(c > n) return 0;
        if(dp[i][p][c] != -1) return dp[i][p][c];
        int skip = fn(i+1, p, c, n, minProfit, group, profit);
        int take = fn(i+1, p + profit[i], c + group[i], n, minProfit, group, profit);
        
        return dp[i][p][c] = (skip + take)%M;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit)
    {
        memset(dp, -1, sizeof(dp));
        return fn(0, 0, 0, n, minProfit, group, profit);
    }
};