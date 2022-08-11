class Solution 
{
public:
  int oddEvenJumps(vector<int>& a) 
  {
        map<int, set<int>> map1, map2;
        int n = a.size();
        for(int i = 0; i < n; i++) 
        {
            map1[a[i]].insert(i);
            map2[-a[i]].insert(i);
        }
        
        vector<int> odd(n, -1), even(n, -1);
        for(int i = 0; i < n; i++) 
        {
            map1[a[i]].erase(i);
            if(map1[a[i]].empty()) map1.erase(a[i]);
            auto it1 = map1.lower_bound(a[i]);
            if(it1 != map1.end()) 
            {
                odd[i] = *(it1->second.begin());
            }
            
            
            map2[-a[i]].erase(i);
            if(map2[-a[i]].empty()) map2.erase(-a[i]);
            auto it2 = map2.lower_bound(-a[i]);
            if(it2 != map2.end()) 
            {
                even[i] = *(it2->second.begin());
            }
        }
        
        vector<vector<bool>> dp(2, vector<bool> (n, false));
        int e = 0, o = 1;
        int ans = 1;
        dp[e][n - 1] = true; 
        dp[o][n - 1] = true;
        for(int i = n - 2; i >= 0; i--) 
        {
            if(odd[i] != -1) dp[o][i] = dp[e][odd[i]];
            if(even[i] != -1) dp[e][i] = dp[o][even[i]];
            if(dp[o][i]) ans++;
        }      
        return ans;
    }
};