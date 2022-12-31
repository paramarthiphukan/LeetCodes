class Solution 
{
public:
    int ans=0;
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0 and j>=0 and i<m and j<n;
    }
    void cal(pair<int,int>& start,pair<int,int> &end,vector<vector<bool>> &vis,int emptySquare,int m,int n)
    {
        emptySquare--;
        if(start==end)
        {
            if(emptySquare==0)
            {
                ans++;
            }
            return ;
        }
        vis[start.first][start.second]=true;
        int x[]={1,-1,0,0};
        int y[]={0,0,1,-1};
        for(int k=0;k<4;k++)
        {
            int newx=start.first+x[k];
            int newy=start.second+y[k];
            if(isValid(newx,newy,m,n) and vis[newx][newy]==false)
            {
                pair<int,int> curr={newx,newy};
                cal(curr,end,vis,emptySquare,m,n);
            }
        }
        vis[start.first][start.second]=false;

    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        pair<int,int> start,end;
        int emptySquare=0;
        vector<vector<bool>> vis(m,vector<bool> (n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    start={i,j};
                }
                if(grid[i][j]==2)
                {
                    end={i,j};
                }
                if(grid[i][j]!=-1)
                {
                    emptySquare++;
                }
                if(grid[i][j]==-1)
                    vis[i][j]=true;
            }
        }
        cal(start,end,vis,emptySquare,m,n);
        return ans;
    }
};