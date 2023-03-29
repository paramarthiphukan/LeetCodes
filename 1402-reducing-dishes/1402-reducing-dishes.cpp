class Solution {
public:
    int fun(vector<int> sat,int k,int in,int n,vector<vector<int> > &dp)
    {
        if(in==n) return 0;
        if(dp[in][k]!=-1) return dp[in][k];
        int ans=sat[in]*k+fun(sat,k+1,in+1,n,dp);
        int ans1=fun(sat,k,in+1,n,dp);
        return dp[in][k]=max(ans,ans1);
    }
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        vector<vector<int> > dp(n+1,vector<int>(n+4));
        sort(sat.begin(),sat.end());
        for(int i=n;i>=0;i--){
            for(int k=n;k>=1;k--){
                if(i==n){
                    dp[i][k]=0;
                }
                else{
                    int ans=sat[i]*k+dp[i+1][k+1];
                    int ans2=dp[i+1][k];
                    dp[i][k]=max(ans,ans2);
                }
            }
        }
        
        return dp[0][1];
        //return fun(satisfaction,1,0,n,dp);
    }
};