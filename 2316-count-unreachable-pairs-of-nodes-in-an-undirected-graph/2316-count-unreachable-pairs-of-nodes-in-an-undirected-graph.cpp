class Solution
{
public:
    vector<int>vis;
    vector<vector<int>>g;
    void dfs(int i,long long &c)
    {
        ++vis[i];
        ++c;
        for(auto&j:g[i])
            if(!vis[j])dfs(j,c);
    }
    long long countPairs(long long n, vector<vector<int>>& edges) 
    {
       long long ans=(n*(n-1))/2;
        vis.resize(n);
        g.resize(n);
        for(auto&i:edges)
        {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;++i)
        {
            if(!vis[i])
            {
                long long c=0;
                dfs(i,c);
                ans-=(c*(c-1))/2;
            }
        }
        return ans;
    }
};