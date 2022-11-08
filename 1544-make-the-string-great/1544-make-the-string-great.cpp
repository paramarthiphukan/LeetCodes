class Solution {
public:
     string makeGood(string s)
     {
        if(s.size()==1 || s=="")
        {
           return s;
        }
        auto it=s.begin();
        while(it<s.end() && s.size()>0)
        {
           if((abs(*it - *(it+1))==32))
           {
               s.erase(it,it+2);
               it=s.begin();
           }
           else
           {
             it++;
           }
           
        }
        
        return s;
    }
};