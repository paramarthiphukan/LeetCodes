class Solution {
public:
  int function(vector<int> &adj,int i,int c,vector<int> &vis,unordered_map<int,int> &map)
  {
        if(vis[i]){
            if(map.find(i)==map.end()) return -1;
            return c-map[i];
        }
        map[i]=c;vis[i]++;
        return (adj[i]!=-1)? function(adj,adj[i],c+1,vis,map):-1;
    }
    int longestCycle(vector<int>& edges) 
    {
        int n=edges.size(),m=-1;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1 and !vis[i])
            {
                unordered_map<int,int> map;
                m=max(m,function(edges,i,0,vis,map));
            }
        }
        return m;
    }
};