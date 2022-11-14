class Solution {
public:
     int dfs(int z, vector<vector<int>>& edges, vector<int>& visited){
        
        if(visited[z]) return 0;
        visited[z] = 1;
        int ret = 1;
        for(int i : edges[z]){
            ret += dfs(i,edges,visited);
        }
        return ret;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visited(n,0);
        
        int ans = 0;
        
        vector<vector<int>> edges(n, vector<int>());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int sz = dfs(i, edges, visited);
                ans += sz - 1;
            }
        }
        
        return ans;
    }
};