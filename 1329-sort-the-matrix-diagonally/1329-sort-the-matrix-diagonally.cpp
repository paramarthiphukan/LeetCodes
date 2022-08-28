class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int i,j,n,m,k,l;
        n = mat.size();
        m=mat[0].size();
        j=n-1,i=0;
        for(j=m-1;j>=0;j--)
        {
            vector<int> a;
            k=i; l=j;
            while(k<n && l<m)
            { 
               a.push_back(mat[k][l]); 
                l++;k++;}
            sort(a.begin(),a.end());
            k=i;l=j;
            int o=0;
            while(k<n &&l<m && o<a.size())
            { mat[k][l] = a[o++]; l++;k++;}
        }
        j=0;
         for(i=1;i<n;i++)
        {
            vector<int> a;
            k=i; l=j;
            while(k<n && l<m)
            { 
               a.push_back(mat[k][l]); 
                l++;k++;}
            sort(a.begin(),a.end());
            k=i;l=j;
            int o=0;
            while(k<n &&l<m && o<a.size())
            { mat[k][l] = a[o++]; l++;k++;}
        }
        return mat;
    }
};