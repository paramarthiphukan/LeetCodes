class Solution {
public:
    bool judgeSquareSum(int c) 
    {
       long long ss;
        long long l = 0;
        long long h = sqrt(c);
        
        while(l<=h)
        {
            ss =  l*l+h*h;
            if(ss == c)
                return true;
            else if(ss>c)
                h--;
            else 
                l++;
        }
        return false; 
    }
};