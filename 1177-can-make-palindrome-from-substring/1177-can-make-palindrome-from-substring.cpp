class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) 
    {
         vector<vector<int>> prefix(s.size()+1,vector<int>(26,0));
        
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<26;j++) prefix[i+1][j]=prefix[i][j];
             prefix[i+1][s[i]-'a']++;
        }
        
         vector<bool> ans(queries.size());
        
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
             int r=queries[i][1];
             int k=queries[i][2];
            
            vector<int> freq(26);
            
            int singles=0;
             for(int j=0;j<26;j++) 
             {
                 int temp=prefix[r+1][j]-prefix[l][j];
                        if(temp&1)
                        {
                            singles++;
                          }     
                   }
             
            
            if( (singles/2)<=k ) ans[i]=1;
              else  ans[i]=0;
            
        }
        return ans;
        
    }
};