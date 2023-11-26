class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = 0;

        if (m == 1)
        {
            int c = 0;
            for(int i = 0; i<n; i++)
            {
                if (matrix[i][0]) {if (++c > maxi) maxi = c;}
                else
                c = 0;
            }
            return maxi;
        }
        if (n == 1)
        {
            int maxi = 0;
            for(int i = 0; i<m; i++)
                if (matrix[0][i]) maxi++;
            return maxi;
        }
        
        vector <vector<int>> q(n,vector<int>(n+1,0));
        for(int i = 0; i<m; i++)
        {
            int start = -1;
            for(int j=0; j<n; j++)
            {
                if(matrix[j][i])
                {
                    if (start == -1) start = j;
                    for (int k=start; k<=j; k++)
                    {
                        int w = j+1 - k;
                        q[k][w]+=w;
                        //if (q[k][w] > maxi) maxi = q[k][w];
                    }
                }
                else start = -1;
            }
        }
        for(int i=0; i<n; i++)
            for( int j=0; j<=n-i; j++)
               if (q[i][j]) maxi = max(q[i][j],maxi);
        return maxi;
    }
};