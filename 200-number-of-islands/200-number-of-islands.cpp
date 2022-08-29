class Solution 
{
public:
     void dfs(vector<vector<char>>& grid, size_t row, size_t col) 
     {
        const size_t rows_s = grid.size();
        const size_t cols_s = grid[0].size();
        
        grid[row][col] = '2';
        if (row > 0u && grid[row - 1][col] == '1') 
        {
            dfs(grid, row - 1, col);
        }
        if (col > 0u && grid[row][col - 1] == '1') 
        {
            dfs(grid, row, col - 1);
        }
        if (row < rows_s - 1u && grid[row + 1][col] == '1') 
        {
            dfs(grid, row + 1, col);
        }
        if (col < cols_s - 1u && grid[row][col + 1] == '1')
        {
            dfs(grid, row, col + 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        const size_t rows_s = grid.size();
        const size_t cols_s = grid[0].size();
        
        size_t num_i = 0u;
        for(size_t i = 0u; i < rows_s; ++i) 
        {
            for(size_t j = 0u; j < cols_s; ++j) 
            {
                if(grid[i][j] == '1') 
                {
                    ++num_i;
                    dfs(grid, i, j);
                }
            }
        }
        return num_i;
    }
};