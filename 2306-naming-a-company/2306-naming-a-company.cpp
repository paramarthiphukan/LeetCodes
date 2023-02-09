class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n=ideas.size();
        vector<unordered_map<string,int> > v(26);
        for(int i=0;i<n;i++)
        {
            int ch=ideas[i][0]-'a';
            string str=ideas[i].substr(1,ideas[i].length()-1);
            v[ch][str]++;
        }
        long long int ans=0;
        for(int i=0;i<26;i++)
        {
            long long int cur1=v[i].size();
            for(int j=i+1;j<26;j++)
            {
                long long int cur2=v[j].size();
                long long int temp=cur1;
                for(auto it=v[j].begin();it!=v[j].end();it++)
                {
                    if(v[i].find(it->first)!=v[i].end())
                    {
                        temp--;
                        cur2--;
                    }
                }
                ans+=(temp*cur2);
            }
        }
        return ans*2;
        
        
    }
};
