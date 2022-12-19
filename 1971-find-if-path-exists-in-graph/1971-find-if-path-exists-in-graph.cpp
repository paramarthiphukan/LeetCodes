class Solution 
{
public:
     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]); 
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";
            
            for(auto it = graph[v].begin(); it != graph[v].end(); it++)
            {
                if(!visited[*it])
                {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
        
        return visited[destination];
    }
};