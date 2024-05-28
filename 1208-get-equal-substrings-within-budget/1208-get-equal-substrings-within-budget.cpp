class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       int n=s.size();
       vector<int>diff(n,0);
        for(int i=0;i<n;i++){
            diff[i]=abs((s[i]-'a')-(t[i]-'a'));
        }
        int res=0,left=0,k=maxCost,sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum>k){
                sum-=diff[left];
                left++;
            }
            res=max(res,i-left+1);
        }
        return res;
    }
};