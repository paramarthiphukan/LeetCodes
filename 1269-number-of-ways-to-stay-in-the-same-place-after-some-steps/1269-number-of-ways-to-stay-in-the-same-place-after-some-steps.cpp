class Solution
{
public:
    int mod = 1e9+7;
    map<pair<int,int>,int>dp;
    int solve(int steps,int arrlen,int currsteps,int currind)
    {
        if(currsteps == steps)
        {
            return (currind == 0)? 1 : 0;
        }
        if(currind < 0 || currind >= arrlen)return 0;

        if(dp.find({currsteps,currind}) != dp.end())return dp[{currsteps,currind}];
        int right = 0, left = 0, stay = 0;
        right = solve(steps,arrlen,currsteps+1,currind+1);
        left = solve(steps,arrlen,currsteps+1,currind-1);
        stay = solve(steps,arrlen,currsteps+1,currind);

        return dp[{currsteps,currind}] = ((right+left)%mod+stay)%mod;
    }
    int numWays(int steps, int arrLen) {
        return solve(steps,arrLen,0,0);
    }
};