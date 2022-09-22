class Solution {
public:
     string reverseWords(string s)
     {
        int i=0;
        int j=0;
        for(i=0;i<s.length();i++)
        {
            j=i;
            while(s[i]!=' ' && i<s.length())
                i++;
            rev(s,j,i-1);
        }
        return s;
    }
    void rev(string &s,int i,int j)
    {
        while(i<=j)
        {
            char t=s[i];
            s[i]=s[j];
            s[j]=t;
            i++;j--;
        }
    }
};