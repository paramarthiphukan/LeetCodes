class Solution 
{
public:
   int sumSubarrayMins(vector<int>& a) 
   {
		int n = a.size();
		vector<int> left_nle(n), right_nle(n);
		stack<int> st;
		//left smallest
		for (int i = 0; i < n; ++i) 
        {
			while (!st.empty() && a[st.top()] > a[i]) st.pop();
			if (!st.empty()) left_nle[i] = st.top();
			else left_nle[i] = -1;
			st.push(i);
		}

		while (!st.empty()) st.pop();

		//right smallest
		for (int i = n - 1; i >= 0; --i) 
        {
			while (!st.empty() && a[st.top()] >= a[i]) st.pop();
			if (!st.empty()) right_nle[i] = st.top();
			else right_nle[i] = -1;
			st.push(i);
		}
		int sum = 0, mod = 1e9 + 7;
		for (int i = 0; i < n; ++i) 
        {
			int left = (left_nle[i] == -1 ? i + 1 : (i - left_nle[i]));
			int right = (right_nle[i] == -1 ? n - i : (right_nle[i] - i));
			sum = (sum + 1LL * a[i] * left * right ) % mod;
		}
		return sum;
	}
};
