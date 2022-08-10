class Solution 
{
public:
   vector<vector<int>>dp;
    int mod=1000000007;
    int solve(int n,int k,int tar)
    {
        if(tar==0 && n==0)
            return 1;
        if(n==0)
            return 0;
        if(tar<=0)
            return 0;
        
        if(dp[n][tar]!=-1)
            return dp[n][tar];
            
        int ans=0;
        
        for(int i=1;i<=k;i++)
        {
            ans=(ans+solve(n-1,k,tar-i))%mod;
        }
        return dp[n][tar]=ans;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        dp.resize(n+1,vector<int>(target+1,-1));
        return solve(n,k,target);
    }
};