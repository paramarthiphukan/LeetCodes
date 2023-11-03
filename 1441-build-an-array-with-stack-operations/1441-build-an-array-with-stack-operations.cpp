class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
       vector<string> res;
        for(int p1=0,p2=1;p1<target.size() && p2<=n; p2++)
        {
            res.push_back("Push");
            if(target[p1]==p2)                
                p1++;
            else
                res.push_back("Pop");
        }
        return res;
    }
};
