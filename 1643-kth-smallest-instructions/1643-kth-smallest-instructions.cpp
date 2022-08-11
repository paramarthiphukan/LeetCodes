class Solution
{
int comb(int n, int m) 
{
        long ans = 1;
        for (int i = 1, j = n - m + 1; i <= m; ++i, ++j) 
        ans = ans * j / i;
        return ans;
    }
public:
    string kthSmallestPath(vector<int>& A, int k) 
    {
        int h = A[1], v = A[0], N = h + v;
        string s;
        for (int i = 0; i < N; ++i) 
        {
            if (h)
            { 
                int c = comb(h - 1 + v, v); 
                if (k <= c) s.push_back('H'), h--; 
                else s.push_back('V'), v--, k -= c; 
            } else s.push_back('V');
        }
        return s;
    }
};