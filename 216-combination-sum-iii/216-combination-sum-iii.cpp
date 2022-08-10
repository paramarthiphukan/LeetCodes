class Solution {
public:
      vector<vector<int>> combinationSum3(int k, int n) 
      {
        vector<vector<int>> result;
        vector<int> sub;
        
        backtracking(1, 0, k, n, sub, result);
        return result;
    }
    
    void backtracking(int start, int sum, int k, int n, vector<int> &sub, vector<vector<int>> &res)
    {
        if(sub.size()==k)
        {
            if(sum == n)
                res.push_back(sub);
            return;
        }
        if(sum>n) return;
        
        for(int i=start; i<10; ++i)
        {
            sub.push_back(i);
            sum += i;
            backtracking(i+1, sum, k, n, sub, res);
            sum -= i;
            sub.pop_back();
        }
    }
};