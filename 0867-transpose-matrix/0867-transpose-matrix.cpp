class Solution {
public:
    public:
        void swap(int &a, int &b)
        {
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }

    vector<vector < int>> transpose(vector<vector < int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if (n == m)
        {
           	// square matrix
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < m; ++j) swap(matrix[i][j], matrix[j][i]);
            return matrix;
        }
        else
        {
           	//non square matrix
            vector<vector < int>> ans(m, vector<int> (n, 0));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    ans[j][i] = matrix[i][j];
            return ans;
        }
    }
};