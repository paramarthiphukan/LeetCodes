class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int arr[27]={0};
        int res=-1;
        for(int i=0;i<s.size();i++)
        {
        if(arr[s[i]-'a']==0)
        arr[s[i]-'a']=i+1;//because we use 1s based indexing
        res=max(res,(i+1-arr[s[i]-'a']-1));
//we subtract 1 because the character itself is not included in the  substring 
        }
        return res;
        
    }
};