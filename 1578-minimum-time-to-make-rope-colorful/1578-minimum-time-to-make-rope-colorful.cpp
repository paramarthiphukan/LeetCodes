class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
       int ans=0;
       colors='{'+colors;
       int n=colors.size();
        for(int i=1;i<n;i++)
        {
             int cost,mn;
             cost=i==1?0:neededTime[i-2];
             mn=i==1?0:neededTime[i-2];
            for(i;i<n&&colors[i]==colors[i-1];i++)
            {
                cost+=neededTime[i-1];
                mn=max(mn,neededTime[i-1]);
            }
            
            ans+=cost-mn; 
            
        }
        return ans;
    }
};
