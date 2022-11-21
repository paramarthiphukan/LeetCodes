class Solution 
{
public:
      vector<vector<int>>v={{1,0},{-1,0},{0,+1},{0,-1}};
     int solve(vector<vector<char>> maze,int n,int m ,int sr,int sc,bool travel)
     {
        queue<pair<int,int>>q;
        q.push({sr,sc});
         int res=0; 
          maze[sr][sc]='!';
        while(!q.empty())
        {
            int size=q.size();
         for(int l=0;l<size;l++)
         {
            auto t=q.front();
             q.pop();
             int i=t.first;
             int j=t.second;
            
              if((i==0 || j==0 || i==n-1 || j==m-1) && travel)
              {
                   return res;
               }
              for(int k=0;k<4;k++){
                  int i1=i+v[k][0];
                  int j1=j+v[k][1];
                  
                  if(i1>=0 && j1>=0 && i1<n && j1<m && maze[i1][j1]!='!' && maze[i1][j1]!='+')
                  {
                       travel = true;
                        maze[i1][j1]='!';
                       q.push({i1,j1});
                   } 
              }
          }
          res++;
        }
         return -1;
     }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int n=maze.size();
        int m=maze[0].size();
         
        int ans=solve(maze,n,m,entrance[0],entrance[1],false);
        if(ans==1e8)
        {
            return -1;
        }
       return ans;
    }
};