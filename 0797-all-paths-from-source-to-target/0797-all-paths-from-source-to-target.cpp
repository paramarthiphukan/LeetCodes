class Solution 
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        queue<vector<int>> q;
        q.push(path);

        while(!q.empty())
        {
            path=q.front(); q.pop();
            int node=path.back();

            if(node==n-1) 
                ans.push_back(path);

            for(auto &it:graph[node])
            {
                vector<int> v(path);
                v.push_back(it);
                q.push(v);
            }
        }

        return ans;
    }
};