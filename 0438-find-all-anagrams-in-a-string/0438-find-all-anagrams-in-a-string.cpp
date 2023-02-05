class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>v;
        unordered_map<char, int>mp,ms;
        for(int i=0; p[i]; i++)
        mp[p[i]]++;
        int i=0, j=0;
        while(j<s.length())
        {
            ms[s[j]]++;
            if(j-i+1 < p.length())
                j++;
            else if(j-i+1 == p.length())
            {
                if(ms == mp)
                    v.push_back(i);
                j++;
            }
            else
            {
                ms[s[i]]--;
                if(ms[s[i]]==0)
                    ms.erase(s[i]);
                i++;
                if(ms == mp)
                    v.push_back(i);
                j++;
            }
        }
        return v;  
    }
};