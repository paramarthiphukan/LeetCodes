class Solution {
public:
   void rotate(vector<vector<int>>& matrix) 
   {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v[j][n-i-1]=matrix[i][j];
            }
        }
        matrix = v;
    }
};