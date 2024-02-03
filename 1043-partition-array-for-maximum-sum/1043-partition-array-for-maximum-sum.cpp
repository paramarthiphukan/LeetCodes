class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--)
        {
            int max_el = INT_MIN;
            for(int j = i; j <= min(n, i+k)-1; j++) 
            {
                max_el = max(max_el, arr[j]);
                dp[i] = max(dp[i], max_el*(j-i+1) + dp[j+1]);
            }
        }
        return dp[0];
    }
};