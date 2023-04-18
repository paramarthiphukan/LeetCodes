class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
       int n=max(word1.size(),word2.size());
        string s;
        
        int i;
        for(i=0;i<n;i++)
        {
         
            if(word1.size()>i)
            {
                s+=word1[i];
            }
            if(word2.size()>i)
            {
                 s+=word2[i];
            }
        }     
        return s; 
    }
};