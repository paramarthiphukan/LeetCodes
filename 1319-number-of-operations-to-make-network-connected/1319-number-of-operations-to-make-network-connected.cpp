class Solution {
public:
    void dfs(vector<int> ad[],int i,vector<int>&vis){
        for(auto k : ad[i]){
            if(!vis[k]){
                vis[k]=1;
                dfs(ad,k,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& v) {
        if(n-1>v.size())return -1;
        vector<int> ad[n];
        vector<int>vis(n,0);
        int c=0;
        for(auto i:v){
            ad[i[0]].push_back(i[1]);
            ad[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
              if(!vis[i]){
                  vis[i]=1;
                  c++;
                  dfs(ad,i,vis);
              }
        }
        return c-1;
    }
};