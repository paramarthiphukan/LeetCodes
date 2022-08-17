class Solution {
public:
 vector<int> constructArray(int n, int k) 
 {
        vector<int> res(n);
        for(int i = 0;i<=k;i++)
        {
            if(i == 0)
            {
                res[i] = 1;
                continue;
            }
            if(i==1)
            {
                res[i] = k+1;
                continue;
            }
            if(i%2==0)
                res[i] = res[i-2]+1;
            else
                res[i] = res[i-2]-1; 
        }
        for(int i = k+1;i<n;i++)
        {
            res[i] = i+1;
        }
        return res;
    }
};