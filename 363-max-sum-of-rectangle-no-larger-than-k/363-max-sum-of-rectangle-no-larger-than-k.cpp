class Solution {
public:
   int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
   {
        int n = matrix.size(), m = matrix[0].size();
        int ans = INT_MIN;
        
        for(int l = 0; l <m; ++l)
        {
            vector<int> sums(n, 0);
            for(int r = l; r < m; ++r)
            {
                for(int i = 0; i < n; ++i) sums[i] += matrix[i][r];
                
                set<int> st = {0};
                int run_sum = 0;
                
                for(auto &a : sums)
                {
                    run_sum += a;
                    auto it = st.lower_bound(run_sum - k);
                    if(it != st.end()) ans = max(ans, run_sum - *it);
                    st.insert(run_sum);
                }
            }
        }
        return ans;
   }
};