class Solution 
{
public:
    string simplifyPath(string path) 
    {
        stack<string> s;
        string res;
        int n= path.size();
        for(int i=0; i<n; i++)
        {
            if(path[i]=='/') continue;
            
            string temp ="";
            while(i<n && path[i]!= '/')
            {
                temp += path[i];
                i++;
            }
            if(temp==".") continue;
            else if(temp == "..")
            {
                if(!s.empty())
                {
                    s.pop();
                }
            }
            else s.push(temp);
        }
        
        while(!s.empty())
        {
            res = "/" + s.top()+ res;
            s.pop();
        }
        if(res.size()==0) res ="/";
        
        return res;
    }
};