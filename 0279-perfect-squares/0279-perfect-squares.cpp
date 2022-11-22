class Solution 
{
public:
    int numSquares(int n) 
    {
         vector<int> dp(n+1, INT_MAX);
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        int val = sqrt(i);
        if(val*val == i) 
        {
            dp[i] = 1;
            continue;
        }
        
        for(int j = 1; j <= sqrt(i); j++) 
        {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    
    return dp[n];
}
    };