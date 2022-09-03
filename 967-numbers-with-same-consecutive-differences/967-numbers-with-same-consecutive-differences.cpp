class Solution {
public:
      void solve(int n, const int& k, int answer, vector<int>& answers)
      {
        if(n <= 0)
        {
            answers.push_back(answer);
            return;
        }
        int mod = answer%10;
        if(mod + k < 10)
        {
            solve(n-1, k, answer * 10 + mod + k , answers);
        }
        if(k && mod - k >= 0)
        {
            solve(n-1, k, answer * 10 + mod - k , answers);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) 
    {
        vector<int> answers;
        for(int i=1; i<=9; i++)
        {
            solve(n - 1, k, i, answers);
        }
        return answers;
    }
};