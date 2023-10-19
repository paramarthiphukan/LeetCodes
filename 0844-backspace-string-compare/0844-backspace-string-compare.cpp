class Solution {
public:
    string updateBacks(string s)
    {
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='#')
            {
                if(ans.length()>0){ans.pop_back();}
            }
            else{ans+=s[i];}
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) 
    {
        s=updateBacks(s);
        t=updateBacks(t);
        if(s.length()!=t.length()){return false;}
        else{
            for(int i=0;i<s.length();i++)
            {
                if(s[i]!=t[i]){return false;}
            }
        }
        return true;
    }
};