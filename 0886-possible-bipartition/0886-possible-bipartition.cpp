class Solution {
public:
    bool dfs( vector<int> adj[],vector<int> &color,int node)
    {
        bool ans=true;
        for(auto i: adj[node])
        {
            if(color[i]==-1)
            {
                color[i]=1-color[node];
                ans=ans and dfs(adj,color,i);
            }
            else
            {
                if(color[i]==color[node]) return false;
            }
        }
        return ans;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        vector<int> adj[n+1];
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(n+1,-1);
        bool b=true;
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
                b=b and dfs(adj,color,i);
            }
        }
        return b;
    }
};