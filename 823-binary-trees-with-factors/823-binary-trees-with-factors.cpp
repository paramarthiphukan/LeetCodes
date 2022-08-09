class Solution {
public:
     int m = 1e9 + 7;
     unordered_map<int, int> s;
     long long int dp[1001];
     long long int help(vector<int>& arr, int i)
     {
        if(i == arr.size())
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        long long int an = 0;
        for(int j = i - 1; j >= 0; j--)
        {
            if(s.find(arr[i]/arr[j]) != s.end() && arr[i]%arr[j] == 0)
            {
             unsigned long long int a = ((help(arr, j)%m)*((help(arr, s[arr[i]/arr[j]]))%m))%m;
                an = (an%m + a%m)%m;
            }
        }
        return dp[i] = (an + 1)%m;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < arr.size(); i++)
        {
            s[arr[i]]=i;
        }
        int ans = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            ans = (ans + help(arr, i))%m;
        }
        return ans;
    }
};