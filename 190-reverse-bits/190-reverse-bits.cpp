class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t res = 0;
        for (int a = 0 ; a< 32 ; a ++) 
        {
            auto k = n & 1;
            res = res << 1;
            res = k | res;
            n =  n >> 1;
        }
        return res;
    }
};