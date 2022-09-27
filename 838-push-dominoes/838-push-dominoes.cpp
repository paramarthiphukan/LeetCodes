class Solution
{
public:
    string pushDominoes(string s)
    {
		int n = s.size();
		vector<int> l(n, 0), r;
		int ct = 0;
		for (auto &e : s)
        {
			if (e == 'R')
            {
				ct = 1;
			}
			else if (ct && e == '.') 
            {
				ct++;
			}
			else if (e == 'L') ct = 0;
			r.push_back(ct);
		}
		for (int i = n - 1; i >= 0; --i)
        {
			char e = s[i];
			if (e == 'L')
            {
				ct = 1;
			}
			else if (ct && e == '.') 
            {
				ct++;
			}
			else if (e == 'R') ct = 0;
			l[i] = ct;
		}
		string ans;
		for (int i = 0; i < n; ++i) 
        {
			if (s[i] == '.')
            {
				if (l[i] == r[i]) ans.push_back('.');
				else if (l[i] == 0) ans.push_back('R');
				else if (r[i] == 0) ans.push_back('L');
				else if (l[i] < r[i]) ans.push_back('L');
				else  ans.push_back('R');
			}
			else ans.push_back(s[i]);
		}
		return ans;
	}
};