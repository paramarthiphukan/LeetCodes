class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
    int n = adjacentPairs.size();
    n++;
    vector<int> ans(n);
    
    map<int,vector<int>> m;
    for(int i=0;i<adjacentPairs.size();i++)
    {
        m[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
        m[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
    }
   
    bool f = 0;
    map<int,vector<int>> ::iterator it=m.begin();
    
    for(it = m.begin();it!=m.end();it++)
    {
        if(!f && it->second.size()==1)
        {
            
            ans[0] = it->first;
            ans[1] = it->second[0];
            f =1;
        }
        else if(f && it->second.size()==1)
        {
            ans[n-1] = it->first;
            ans[n-2] = it->second[0];
        }
        else
            continue;
    }
    
    int t = n;
    int i = 1;
    while(i<n-1)
    {
        int x = m[ans[i]][0];
        int y = m[ans[i]][1];
        if(ans[i-1]==x)
            ans[i+1] = y; 
        else
            ans[i+1] = x;
        
        i++;
         
    }
    return ans;
}
};