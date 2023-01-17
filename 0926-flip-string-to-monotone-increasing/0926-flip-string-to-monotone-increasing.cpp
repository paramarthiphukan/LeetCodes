class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0;
        int c1 = 0;
        for(char c : s)
        {
            if(c == '0')
            {
                if(c1>0)res+=1;
            }
            else 
            {
                c1+=1;       
            }
            res=min(res,c1);
        }
        return res;
    }
};