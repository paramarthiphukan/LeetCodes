class Solution 
{
public:
       int concatenatedBinary(int n)
       {  
        long long mod = 1e9 + 7;
        long long res = 0;
        for(int i = 1; i <= n; i++)
        {
            int len = 0;
            int num = i;
            while(num)
            {
                len++;
                num = num >> 1;
            }  
            res = (res << len) % mod;
            res = (res % mod + i % mod) % mod;
        }
        
        return res % mod;
    }
};