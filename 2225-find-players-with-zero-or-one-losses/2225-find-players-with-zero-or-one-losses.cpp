class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        unordered_map<int,int> a,b;
        for(auto m:matches)
        {
            int r=m[0];
            int s=m[1];
            a[r]++;
            b[s]++;
        }
        vector<int> a1,a2;
        for(auto t:b)
        {
            if(t.second==1)
                a2.push_back(t.first);
        }
        sort(a2.begin(),a2.end());
        for(auto t:a)
        {
            if(b[t.first]==0)
                a1.push_back(t.first);
        }
        sort(a1.begin(),a1.end());
        vector<vector<int>> ans;
        ans.push_back(a1);
        ans.push_back(a2);
        return ans;
    }
};