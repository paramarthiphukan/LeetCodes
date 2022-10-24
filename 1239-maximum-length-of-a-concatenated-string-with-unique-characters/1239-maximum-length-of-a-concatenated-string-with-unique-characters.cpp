class Solution
{
    public:
    int maxLength(vector<string>& arr) 
    {
        vector<bitset<26>> m; 
        int res=0;
        for(auto& s : arr)
        {
            bitset<26> bits;
            for(char c:s) bits.set(c-'a');
            int n = bits.count();
            if(n != s.size()) continue;
            for(int i=m.size()-1; i>=0; i--) 
            {
                auto& b = m[i];
                if((b & bits).any())
                    continue;
                res = max<int>(res, b.count() + n);
                m.push_back(b | bits);
            }
            m.push_back(bits);
            res=max<int>(res, n);
        }
        return res;
    }
};