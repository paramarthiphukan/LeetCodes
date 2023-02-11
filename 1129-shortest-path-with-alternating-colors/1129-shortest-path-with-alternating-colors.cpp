class Solution
{
    vector<vector<int>> redNodes, blueNodes;
    vector<vector<int>> moves;
    
    void dfs(int i, int move, int flag)
    {
        if(move >= moves[i][flag])
            return;
            
        moves[i][flag] = min(move, moves[i][flag]);
        
        if(flag == 0)
            for(auto j : redNodes[i])
                dfs(j, move+1, 1);
        if(flag == 1)
            for(auto j : blueNodes[i])
                dfs(j, move+1, 0);
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        redNodes.resize(n);
        blueNodes.resize(n);
        moves.resize(n, vector<int>(2,1e3));
        
        for(auto edge : redEdges)
            redNodes[edge[0]].push_back(edge[1]);
        for(auto edge : blueEdges)
            blueNodes[edge[0]].push_back(edge[1]);
        
        dfs(0, 0, 0);   
        dfs(0, 0, 1);
        
        vector<int> ans(n);
        for(int i = 0; i<n; i++)
        {
            int move = min(moves[i][0], moves[i][1]);
            
            if(move == 1e3)
                ans[i] = -1;
            else
                ans[i] = move;
        }
        
        return ans;
    }
};