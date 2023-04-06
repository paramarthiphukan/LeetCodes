class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,int n,int m,int drow[],int dcol[])
    {
       vis[i][j]=1;
       for(int k=0;k<4;k++)
       {
           int nrow=drow[k]+i;
           int ncol=dcol[k]+j;
           if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]==0)
           {
               dfs(nrow,ncol,grid,vis,n,m,drow,dcol);
           }
       }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
       for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && grid[0][j]==0)
            {
                dfs(0,j,grid,vis,n,m,drow,dcol);
            }
            if(!vis[n-1][j]&& grid[n-1][j]==0)
            {
                dfs(n-1,j,grid,vis,n,m,drow,dcol);
            }
        }
        for(int i=0;i<n;i++)
        {
           if(!vis[i][0]&& grid[i][0]==0)
           {
               dfs(i,0,grid,vis,n,m,drow,dcol);
           }
           if(!vis[i][m-1] && grid[i][m-1]==0)
           {
               dfs(i,m-1,grid,vis,n,m,drow,dcol);
           }
        }
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(grid[i][j]==0 && !vis[i][j])
                {
                    cnt++;
                    dfs(i,j,grid,vis,n,m,drow,dcol);
                }
            }
        }
        return cnt;
    }
};