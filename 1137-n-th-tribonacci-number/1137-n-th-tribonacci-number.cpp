class Solution
{
public:
    int tri(int n, vector<int>&dp)
    {
        
        if(dp[n]==-1)
        {
            int res;
            if(n==0 || n==1)
            {
                return n;
            }
            else if(n==2)
            {
                return 1;
            }
            
            else res=tri(n-1,dp)+tri(n-2,dp)+tri(n-3,dp);
            dp[n]=res;
        }
        return dp[n];
    }
    
    int tribonacci(int n) 
    {
        vector<int>dp(n+1,-1);
        return tri(n,dp);
    }
};