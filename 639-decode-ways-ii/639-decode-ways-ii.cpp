class Solution 
{
public:
   long dp[100001];
    int mod=1e9+7;
    long func(string &s, int i, int n)
    {
        if(i==n)
        {
            return 1;
        }
        
        if(s[i]=='0')
        {
            return dp[i]=0;
        }
        
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        
        int cnt=0;
        if(i+1<n and s[i]=='*' and s[i+1]=='*')
        {
            cnt+=(15*func(s,i+2,n)%mod)%mod;
        }else if(i+1<n and s[i]=='*' and s[i+1]!='*')
        {
            int num=s[i+1]-'0';
            if(num>=0 and num<=6)
            {
                cnt+=(2*func(s,i+2,n)%mod)%mod;
            }else{
                cnt+=func(s,i+2,n)%mod;
            }
        }else if(i+1<n and s[i]!='*' and s[i+1]=='*')
        {
            int num=s[i]-'0';
            if(num==1)
            {
                cnt+=(9*func(s,i+2,n)%mod)%mod;
            }else if(num==2)
            {
                cnt+=(6*func(s,i+2,n)%mod)%mod;
            }
        }else if(i+1<n)
        {
            int num=(s[i]-'0')*10+s[i+1]-'0';
            if(num>=1 and num<=26)
            {
                cnt+=func(s,i+2,n)%mod;
            }
        }
        
        if(s[i]=='*')
        {
            return dp[i]=cnt+(9*func(s,i+1,n)%mod)%mod;
        }
        else
        {
            return dp[i]=cnt+func(s,i+1,n)%mod;
        }
        
    }
    
    int numDecodings(string &s)
    {
        memset(dp,-1,sizeof(dp));
        return func(s,0,s.size())%mod;
    }
};