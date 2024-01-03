class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for(string b:bank)
        {
            int count=0;
            for(int i=0;i<b.size();i++)
            {
                if(b[i]=='1')
                    count++;
            }
            if(count>0)
                v.push_back(count);
        }
        int result=0;
        for(int i=1;i<v.size();i++)
            result+=v[i]*v[i-1];
        return result;
    }
};