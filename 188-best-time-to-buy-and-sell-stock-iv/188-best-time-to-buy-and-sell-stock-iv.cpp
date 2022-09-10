class Solution {
public:
 int profit(int k, vector<int>&prices, int idx, int n, vector<vector<int>>&dp)
 {
        if(k==0 || idx>=n)
        {
            return 0;
        }
        if(dp[idx][k]!=-1)
        {
            return dp[idx][k];
        }
        int ans=0;
        for(int i=idx+1; i<n; i++)
        {
            if(prices[i]>prices[idx])
            {
                ans=max(ans, prices[i]-prices[idx] + profit(k-1, prices, i+1, n, dp));
            }
        }
        ans=max(ans, profit(k, prices, idx+1, n, dp));
        return dp[idx][k]=ans;
    }
    int maxProfit(int k, vector<int>& prices) 
    {
        if(prices.size()<=1)
        {
            return 0;
        }
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return profit(k,prices,0,n,dp);
    }
};