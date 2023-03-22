class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>> > adj;
        for(auto p:roads){
            int u=p[0];
            int v=p[1];
            int wt=p[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int mindist=INT_MAX;
        vector<int> vis(n+1,0);
        dfs(1,n,adj,mindist,vis);
        return mindist;
    }
    void dfs(int u,int n,unordered_map<int,vector<pair<int,int>> > &adj, int &mindist,vector<int> &vis){
        vis[u]=1;
        for(auto p:adj[u]){
            int v=p.first;
            int wt=p.second;
            mindist=min(mindist, wt);
            if(!vis[v]){
                dfs(v,n,adj, mindist,vis);
            }
        }
    }
};