class Solution
{
public:
     int f(vector<int>& v,int t) 
    {
        int n=v.size(),s=0,c=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0;i<n;i++)
        {
            s+=v[i];
            if(m.find(s-t)!=m.end())
                c+=m[s-t];
            m[s]++;
        }
        return c;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& a, int t) 
    {
        int r=0;
        int n=a.size(),m=a[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int> v(m);
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                    v[k]+=a[j][k];
                r+=f(v,t);
            }
        }
        return r;
    }
};
