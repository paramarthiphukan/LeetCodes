class Solution {
public:
      unordered_map< string ,bool> m;
    vector< string> ans;
    void puzzle( string s, string x ,string an,int in )
    {
        if(in==s.size())
        {
            an.pop_back();
            ans.push_back(an);
        }
        for(int i=in;i<s.length();i++)
        {
            x+=s[i];
            if(m.find(x)!=m.end())
            {
                puzzle(s,"",an+x+" ",i+1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wd) 
    {
        
        for(string st:wd) m[st]=true;
        puzzle(s,"","",0);
        return ans;
        
    }
};