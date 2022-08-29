class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid)
    {
         int n = grid.size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int up = i - 1 >= 0 ? grid[i - 1][j] : 0;
                int down = i + 1 < n ? grid[i + 1][j] : 0;
                int left = j - 1 >= 0 ? grid[i][j - 1] : 0;
                int right = j + 1 < n ? grid[i][j + 1] : 0;
                int val = grid[i][j];
                if(left < val)
                {
                    res = res + (val - left);
                }
                if(right < val)
                {
                    res = res + (val - right);
                }
                if(up < val)
                {
                    res = res + (val - up);
                }
                if(down < val)
                {
                    res = res + (val - down);
                }
                if(val >= 1) res += 2;
            }
        }
        return res;
    
    }
};