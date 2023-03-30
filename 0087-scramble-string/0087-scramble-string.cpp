class Solution 
{
public:
     map<pair<string,string>,int> mp;
    bool solve(string a, string b)
    {
        if(mp.find({a,b}) != mp.end())
        {
            return mp[{a,b}];
        }
        
        if(a.compare(b)==0)
        {
            return mp[{a,b}]=true;
        }
        
        vector<int> cnt(26,0);
        for(int i=0;i<a.size();i++)
        {
            cnt[a[i]-'a']++;
            cnt[b[i]-'a']--;
        }
        for(auto i: cnt)
        {
            if(i != 0)
            {
                return mp[{a,b}]=false;
            }
        }
        
        int n=a.size();
        for(int k=1; k<n; k++)
        {
            if(solve(a.substr(0,k),b.substr(0,k))&&solve(a.substr(k),b.substr(k))){
                return mp[{a,b}]=true;
            }
            if(solve(a.substr(0,k),b.substr(n-k))&&solve(a.substr(k),b.substr(0,n-k)))
            {
                return mp[{a,b}]=true;
            }
        }
        return mp[{a,b}]=false;
    }
    bool isScramble(string s1, string s2) 
    {
        if(!s1.size() || s1.size()!=s2.size())
        {
            return false;
        }
        return solve(s1, s2);
    }
};